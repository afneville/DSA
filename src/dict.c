#include "stdlib.h"
#include "./includes/dict.h"

ds_node * create_ds_node(object * new_data, char * key) {

    ds_node * new_node = (ds_node *) malloc(sizeof(ds_node));
    new_node->record = new_data;
    new_node->next = NULL;
    new_node->key = key;
    return new_node;

}

void destroy_ds_node(ds_node * old_node) {
    destroy_object(old_node->record);
    free(old_node);
}
