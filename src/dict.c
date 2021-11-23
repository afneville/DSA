#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "../include/llist.h"
#include "../include/dict.h"
#include "../include/logger.h"
#include "../include/primes.h"

dict * tmp_dict = NULL;

unsigned long hash(char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}


dict * new_dict(collision_resolution_method collision_approach,
        resize_method resize_approach, int size, int primes_array_index) {

    dict * self = (dict *) malloc(sizeof(dict));

    self->array = (node **) malloc(sizeof(node *) * size);
    self->primes_array_index = primes_array_index;
    self->size = size;
    self->num_entries = 0;
    self->collision_approach = collision_approach;
    self->resize_approach = resize_approach;

    return self;

}

void del_dict(dict * old_dict){
    free(old_dict->array);
    free(old_dict);
}

node * search_dict(dict * self, char * key) {

    node * target = new_node(NULL, key);
    target->hash = hash(key);

    for (int i = 0; i < self->size; i ++){
        int index = (target->hash + i) % self->size;
        if (!self->array[index]) {
            return NULL;
        } else {
            node * data = traverse_llist(self->array[index], target, search_callback);
            if (data) {
                return data;
            } else if (self->collision_approach == DirectChaining) {
                break;
            }
        }
    }
    return NULL;
}

int ins_dict(dict * self, char * key, object * insert_data, int dynamic) {

    node * insert_node = new_node(insert_data, key);
    insert_node->hash = hash(insert_node->key);

    for (int i = 0; i < self->size; i++){
        int index = (insert_node->hash + i) % self->size;
        if (self->array[index]) {
            if (strcmp(self->array[index]->key, key) == 0) {
                return -1;
            } else if (self->collision_approach == DirectChaining) {
                traverse_llist(self->array[index], insert_node, append_llist_unique);
                return llist_flag;
            }
        } else if (!self->array[index]) {
            self->array[index] = insert_node;
            self->num_entries++;
            if (dynamic)
                maintain_dict(self);
            return 0;
        }
    }
    return -1;

}

float calc_load_factor(dict * self) {
    float load_factor = ((float) self->num_entries) / ((float) self->size);
    return load_factor;
}

void maintain_dict(dict * self) {

    float load_factor = calc_load_factor(self);
    printf("%f\n", load_factor);
    int new_prime_index;
    int new_size;

    if (load_factor > 0.75) {
        for (new_prime_index = self->primes_array_index; new_prime_index < num_detected_primes; new_prime_index++) {
            if (primes_array[new_prime_index] > 2 * self->size) {
                new_size = primes_array[new_prime_index];
                break;
            }
        }
    } else if (load_factor < 0.25) {
        for (new_prime_index = self->primes_array_index; new_prime_index < num_detected_primes; new_prime_index--) {
            if (primes_array[new_prime_index] < 0.5 * self->size) {
                new_size = primes_array[new_prime_index];
                break;
            }
        }
    } else {
        return;
    }

    printf("resizing: %d\n", new_size);
    // destroy_dictionary(tmp_dict);
    tmp_dict = new_dict(self->collision_approach, self->resize_approach, new_size, new_prime_index);


    for (int i = 0; i < self->size; i++) {
        // if (self->array[i] && self->array[i]->record) {
        //     // insert_dictionary(tmp_dict, self->array[i]->key, self->array[i]->record, 0);
        // }
        traverse_llist(self->array[i], NULL, ins_callback);

    }

    // remember to deallocate old array
    self->array = tmp_dict->array;
    self->size = new_size;
    self->primes_array_index = new_prime_index;

    return;

}
