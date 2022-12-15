#include "../inc/item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

item * new_item(item_type type, ...) {
    va_list args;
    va_start(args, 1);
    item * new_ptr = (item *) malloc(sizeof(item));
    new_ptr->type = type;
    switch ( new_ptr->type ) {
        case Integer: new_ptr->val.int_val = va_arg(args, int); break;
        case Double: new_ptr->val.dbl_val = va_arg(args, double); break;
        case Float: new_ptr->val.flt_val = (float) va_arg(args, double); break;
        case Character: new_ptr->val.char_val = (char) va_arg(args, int); break;
        case String: new_ptr->val.str_val = va_arg(args, char *); break;
        case Pointer: new_ptr->val.ptr_val = va_arg(args, void *); break;
        default: break;
    }
    va_end(args);
    return new_ptr;
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
