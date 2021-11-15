#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "./includes/dict.h"
#include "./includes/logger.h"


unsigned long hash(char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}


dict * create_dictionary(collision_resolution_method collision_approach,
        resize_method resize_approach, int size, int primes_array_index) {

    dict * self = (dict *) malloc(sizeof(dict));

    self->buckets = (ds_node **) malloc(sizeof(ds_node *) * size);
    self->primes_array_index = primes_array_index;
    self->num_buckets = size;
    self->num_entries = 0;
    self->collision_approach = collision_approach;
    self->resize_approach = resize_approach;

    return self;

}

void destroy_dictionary(dict * old_dict){
    free(old_dict->buckets);
    free(old_dict);
}

ds_node * search_dictionary(dict * self, char * key) {

    /* ds_node * target = create_ds_node(NULL, key); */
    unsigned long key_hash = hash(key);
    // fprintf(fp, "DICT SEARCH: ", key_hash);

    for (int bucket = 0; bucket < self->num_buckets; bucket ++){
        int index = (key_hash + bucket) % self->num_buckets;
        // fprintf(fp, "%d\n", index);
        if (!self->buckets[index]) {
            return NULL;
        } else {

            // fprintf(fp, "stored key: %s, current key: %s\n", existing_dict->buckets[index]->key, key);
            if (strcmp(self->buckets[index]->key, key) == 0)
                return self->buckets[index];
        }
    }
    // fprintf(fp, "checked all buckets\n");
    return NULL;

}

int insert_dictionary(dict * self, char * key, object * insert_data) {

    ds_node * insert_node = create_ds_node(insert_data, key);
    insert_node->hash = hash(insert_node->key);
    fprintf(fp, "DICT:HASH:%lu:", insert_node->hash);

    for (int i = 0; i < self->num_buckets; i++){
        int index = (insert_node->hash + i) % self->num_buckets;
        if (self->buckets[index]) {
            if (strcmp(self->buckets[index]->key, key) == 0) {
                fprintf(fp, "POSITION: KEY EXISTS\n");
                return -1;
            }
        } else if (!self->buckets[index]) {
            fprintf(fp, "POSITION: %d\n", index);
            self->buckets[index] = insert_node;
            self->num_entries++;
            return 0;
        }
    }
    fprintf(fp, "POSITION: DICTIONARY FULL\n");
    return -1;

}

float calc_load_factor(dict * self) {
    float load_factor = (float) self->num_entries / self->num_buckets;
    return load_factor;
}

void resize_dictionary(dict * self);
