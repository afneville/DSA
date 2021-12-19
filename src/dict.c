#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "../inc/list.h"
#include "../inc/dict.h"
#include "../inc/logger.h"
#include "../inc/primes.h"

dict * tmp_dict = NULL;

unsigned long hash(char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}


dict * new_dict(resolve collision_approach,
        resize resize_approach, int size, int primes_array_index) {

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

    node * target = new_node();
    target->key = key;
    target->hash = hash(key);

    for (int i = 0; i < self->size; i ++){
        int index = (target->hash + i) % self->size;
        if (!self->array[index]) {
            return NULL;
        } else {
            node * data = traverse_list(self->array[index], target, Forwards, search_callback);
            if (data) {
                return data;
            } else if (self->collision_approach == DirectChaining) {
                break;
            }
        }
    }
    return NULL;
}

void rm_dict(dict * self, char * key) {

    node * target = new_node();
    target->key = key;
    target->hash = hash(key);

    for (int i = 0; i < self->size; i ++){
        int index = (target->hash + i) % self->size;
        if (!self->array[index]) {
            return;
        } else if (self->collision_approach == DirectChaining){
            if (self->array[index]->next) {
                node * data = traverse_list(self->array[index], target, Forwards, del_item_by_key);
            } else {
                
            }
        } else {
                break;
        }
    }
    return;
}

int ins_dict(dict * self, char * key, object * insert_data, int dynamic) {

    node * node_p = new_node();
    node_p->key = key;
    node_p->record = insert_data;

    node_p->hash = hash(node_p->key);

    for (int i = 0; i < self->size; i++){
        int index = (node_p->hash + i) % self->size;
        if (self->array[index]) {
            if (strcmp(self->array[index]->key, key) == 0) {
                return -1;
            } else if (self->collision_approach == DirectChaining) {
                traverse_list(self->array[index], node_p, Forwards, append_list_unique_key);
                return llist_flag;
            }
        } else if (!self->array[index]) {
            self->array[index] = node_p;
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
        traverse_list(self->array[i], NULL, Forwards, ins_dict_callback);

    }

    // remember to deallocate old array
    self->array = tmp_dict->array;
    self->size = new_size;
    self->primes_array_index = new_prime_index;

    return;

}
