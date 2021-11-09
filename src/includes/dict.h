#ifndef dict_H
#define dict_H
#include "./object.h"

typedef struct ds_node_T {
    object * record;
    struct ds_node_T * next;
    char * key;
    int hash;
} ds_node;

ds_node * create_ds_node(object * new_data);
void destroy_ds_node(ds_node * old_node);

#endif // dict_H
