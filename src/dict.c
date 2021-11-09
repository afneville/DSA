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

dict * create_dictionary(){
    dict * new_dict = (dict *) malloc(sizeof(ds_node) * INITIAL_BUCKET_COUNT);
    new_dict->num_buckets = 8;
    return new_dict;
}

void resize_dictionary(dict * existing_dict) {

    return;
}

void destroy_dictionary(dict * old_dict){
    free(old_dict->buckets);
    free(old_dict);
}
