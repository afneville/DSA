#include <stdio.h>
#include <stdlib.h>
#include "./includes/object.h"

object * new_object(object_type type, void * ptr) {

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

void represent(object * ptr) {

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


