#include <stdio.h>
#include <stdlib.h>
#include "../include/object.h"

object * new_obj(obj_type type, void * ptr) {

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

void repr_obj(object * ptr) {

    switch ( ptr->type ) {
        case Integer:
            printf("%d", ptr->data.integer_data);
            break;
        case Decimal:
            printf("%f", ptr->data.decimal_data);
            printf("");
            break;
        case String:
            printf("%s", ptr->data.string_data);
            break;
        default:
            break;

    }
}

void del_obj(object * ptr){
    free(ptr);
};


node * new_node(object * new_data, char * key) {

    node * new_node = (node *) malloc(sizeof(node));
    new_node->record = new_data;
    new_node->next = NULL;
    new_node->key = key;
    return new_node;

}

void del_node(node * old_node) {
    del_obj(old_node->record);
    free(old_node);
}
