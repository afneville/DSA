#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "./includes/dict.h"

ds_node * create_ds_node(object * new_data, char * key) {

    ds_node * new_node = (ds_node *) malloc(sizeof(ds_node));
    new_node->record = new_data;
    new_node->next = NULL;
    new_node->key = key;
    return new_node;

}

unsigned long hash(char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

void destroy_ds_node(ds_node * old_node) {
    destroy_object(old_node->record);
    free(old_node);
}

dict * create_dictionary(){
    dict * new_dict = (dict *) malloc(sizeof(dict));
    new_dict->buckets = (ds_node **) malloc(sizeof(ds_node *) * INITIAL_BUCKET_COUNT);
    new_dict->num_buckets = 8;
    new_dict->num_entries = 0;
    return new_dict;
}

void resize_dictionary(dict * existing_dict) {
    return;
}

void destroy_dictionary(dict * old_dict){
    free(old_dict->buckets);
    free(old_dict);
}

ds_node * search_dictionary(dict * existing_dict, char * key) {

    /* ds_node * target = create_ds_node(NULL, key); */
    unsigned long key_hash = hash(key);
    printf("hash to check %lu\n", key_hash);

    for (int bucket = 0; bucket < existing_dict->num_buckets; bucket ++){
        int index = (key_hash + bucket) % existing_dict->num_buckets;
        printf("%d\n", index);
        if (!existing_dict->buckets[index]) {
            return NULL;
        } else {

            printf("stored key: %s, current key: %s\n", existing_dict->buckets[index]->key, key);
            if (strcmp(existing_dict->buckets[index]->key, key) == 0)
                return existing_dict->buckets[index];
        }
    }
    printf("checked all buckets\n");
    return NULL;

}

int insert_dictionary(dict * existing_dict, char * key, object * insert_data) {

    ds_node * insert_node = create_ds_node(insert_data, key);
    insert_node->hash = hash(insert_node->key);
    printf("hash: %lu\n", insert_node->hash);

    for (int bucket = 0; bucket < existing_dict->num_buckets; bucket ++){
        int index = (insert_node->hash + bucket) % existing_dict->num_buckets;
        if (existing_dict->buckets[index]) {
            if (strcmp(existing_dict->buckets[index]->key, key) == 0)
                return -1;

        } else if (!existing_dict->buckets[index]) {
            printf("inserting in position %d\n", index);
            existing_dict->buckets[index] = insert_node;
            existing_dict->num_entries++;
            return 0;
        }
    }
    return -1;
}
