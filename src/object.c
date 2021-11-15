#include <stdio.h>
#include <stdlib.h>
#include "./includes/object.h"

object * create_object(object_type type, void * ptr) {

    object * new_object = (object *) malloc(sizeof(object));

    switch ( type ) {
        case Integer:
            new_object->type = Integer;
            new_object->data.integer_data = *((int *) ptr);
            break;
        case Decimal:
            new_object->type = Decimal;
            new_object->data.decimal_data = *((float *) ptr);
            break;
        case String:
            new_object->type = String;
            new_object->data.string_data = (char *) ptr;
            break;
        default:
            break;

    }

    return new_object;
}

void repr(object * ptr) {

    switch ( ptr->type ) {
        case Integer:
            printf("%d\n", ptr->data.integer_data);
            break;
        case Decimal:
            printf("%f\n", ptr->data.decimal_data);
            printf("");
            break;
        case String:
            printf("%s\n", ptr->data.string_data);
            break;
        default:
            break;

    }
}

void destroy_object(object * ptr){
    free(ptr);
};


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
