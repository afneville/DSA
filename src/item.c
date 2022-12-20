#include "../inc/item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

unsigned long hash_str_f_(char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

// private functions

void set_repr(item self) {
    int repr_len;
    switch ( self->type ) {
        case Integer: repr_len = snprintf(self->repr, self->repr_len, "%d", self->val.int_val); break;
        case Float: repr_len = snprintf(self->repr, self->repr_len, "%f", self->val.flt_val); break;
        case Double: repr_len = snprintf(self->repr, self->repr_len, "%f", self->val.dbl_val); break;
        case Character: repr_len = snprintf(self->repr, self->repr_len, "'%c'", self->val.char_val); break;
        case String: repr_len = snprintf(self->repr, self->repr_len, "\"%s\"", self->val.str_val); break;
        case Pointer: repr_len = snprintf(self->repr, self->repr_len, "%p", self->val.ptr_val); break;
        default: break;
    }
    if (repr_len >= self->repr_len) {
        self->repr = (char *) realloc(self->repr, sizeof(char) * (repr_len + 1));
        self->repr_len = repr_len + 1;
        set_repr(self);
    }
}

void set_hash(item self) {
    self->hash = hash_str_f_(self->repr);
}

// public funcitons

item item_new(item_type type, ...) {
    va_list args;
    va_start(args, 1);
    item self = (item) malloc(sizeof(struct item_type_T_));
    self->type = type;
    switch ( self->type ) {
        case Integer: self->val.int_val = va_arg(args, int); break;
        case Double: self->val.dbl_val = va_arg(args, double); break;
        case Float: self->val.flt_val = (float) va_arg(args, double); break;
        case Character: self->val.char_val = (char) va_arg(args, int); break;
        case String: self->val.str_val = va_arg(args, char *); break;
        case Pointer: self->val.ptr_val = va_arg(args, void *); break;
        default: break;
    }
    va_end(args);
    self->repr = (char *) malloc(sizeof(char) * DEFAULTREPRSIZE);
    self->repr_len = DEFAULTREPRSIZE;
    set_repr(self);
    set_hash(self);
    return self;
}

void item_del(item self) {
    free(self->repr);
    free(self);
}

void item_modify(item self, item_type type, ...) {
    va_list args;
    va_start(args, 1);
    self->type = type;
    switch ( self->type ) {
        case Integer: self->val.int_val = va_arg(args, int); break;
        case Double: self->val.dbl_val = va_arg(args, double); break;
        case Float: self->val.flt_val = (float) va_arg(args, double); break;
        case Character: self->val.char_val = (char) va_arg(args, int); break;
        case String: self->val.str_val = va_arg(args, char *); break;
        case Pointer: self->val.ptr_val = va_arg(args, void *); break;
        default: break;
    }
    va_end(args);
}

bool item_compare(item self, item other) {
    if (self->type != other->type)
        return false;
    switch ( self->type ) {
        case Integer: return self->val.int_val == other->val.int_val;
        case Float: return self->val.flt_val == other->val.flt_val;
        case Double: return self->val.dbl_val == other->val.dbl_val;
        case Character: return self->val.char_val == other->val.char_val;
        case String: return strcmp(self->val.str_val, other->val.str_val) == 0;
        case Pointer: return self->val.ptr_val == other->val.ptr_val;
        default: break;
    }
}

void item_print(item self) {
    printf("%s", self->repr);
}

char * item_repr(item self) {
    return self->repr;
}

unsigned long item_hash(item self) {
    return self->hash;
}

