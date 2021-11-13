#ifndef dict_H
#define dict_H
#include "./object.h"

#define INITIAL_BUCKET_COUNT 8

typedef struct ds_node_T {
    object * record;
    struct ds_node_T * next;
    char * key;
    unsigned long hash;
} ds_node;

typedef struct dict_T {
    int num_buckets;
    int num_entries;
    ds_node ** buckets;
} dict;

ds_node * create_ds_node(object * new_data, char * key);
void destroy_ds_node(ds_node * old_node);
dict * create_dictionary();

ds_node * search_dictionary(dict * existing_dict, char * key);
int insert_dictionary(dict * existing_dict, char * key, object * insert_data);
void resize_dictionary(dict * existing_dict);
void destroy_dictionary(dict * old_dict);

#endif // dict_H