#include <stdio.h>
#include <stdlib.h>
#include "../inc/object.h"

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

    if (!ptr) {
        printf("NULL");
        return;
    }

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

    return;
}

void del_obj(object * ptr){
    free(ptr);
};


node * new_node() {
    node * node_p = (node *) malloc(sizeof(node));
    node_p->record = NULL;
    node_p->next = node_p->prev = NULL;
    node_p->left = node_p->right = NULL;
    node_p->key = NULL;
    return node_p;
}

void del_node(node * old_node) {
    del_obj(old_node->record);
    free(old_node);
}
