#include "../inc/item.h"
#include <stdio.h>
#include <stdlib.h>

item * new_item(item_type type, void * val_ptr) {
    item * rv = (item *) malloc(sizeof(item));
    rv->type = type;
    switch ( rv->type ) {
        case Integer: rv->val.int_val = *((int *) val_ptr); break;
        case Float: rv->val.flt_val = *((float *) val_ptr); break;
        case Double: rv->val.dbl_val = *((double *) val_ptr); break;
        case Character: rv->val.char_val = *((char *) val_ptr); break;
        case String: rv->val.str_val = (char *) val_ptr; break;
        case Pointer: rv->val.ptr_val = val_ptr; break;
        default: break;
    }
    return rv;
}

void del_item(item * ptr) {
    free(ptr);
}

void print_item(item * ptr) {
    switch ( ptr->type ) {
        case Integer: printf("%d", ptr->val.int_val); break;
        case Float: printf("%f", ptr->val.flt_val); break;
        case Double: printf("%f", ptr->val.dbl_val); break;
        case Character: printf("'%c'", ptr->val.char_val); break;
        case String: printf("\"%s\"", ptr->val.str_val); break;
        case Pointer: printf("%p", ptr->val.ptr_val); break;
        default: break;
    }
}
