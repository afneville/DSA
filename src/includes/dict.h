#ifndef dict_H
#define dict_H
#include "./object.h"

#define INITIAL_BUCKET_COUNT 8

typedef struct ds_node_T {
    object * record;
    struct ds_node_T * next;
    char * key;
    int hash;
} ds_node;

typedef struct dict_T {
    int num_buckets;
    ds_node * buckets;
} dict;

ds_node * create_ds_node(object * new_data, char * key);
void destroy_ds_node(ds_node * old_node);
dict * create_dictionary();
int key_in_dictionary(char * key);
ds_node * retrieve_data(char * key);
void insert_dictionary(char * key, ds_node * insert_data);
void resize_dictionary(dict * existing_dict);
void destroy_dictionary(dict * old_dict);

#endif // dict_H
