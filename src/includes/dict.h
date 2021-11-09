#ifndef dict_H
#define dict_H
#include "./object.h"

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

#endif // dict_H
