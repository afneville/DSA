#include "../inc/list.h"
#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 2


// ADT
list * list_new(list_impl ds) {
    list * self = (list *) malloc(sizeof(list));
    self->ds = ds;
    switch (self->ds) {
        case LinkedList: self->list = llist_new(); break;
        case ArrayList:  self->list = alist_new(); break;
        default: self->list = NULL; break;
    }
    self->append   = &list_append;
    self->prepend  = &list_prepend;
    self->insert   = &list_insert;
    self->access   = &list_access;
    self->update   = &list_update;
    self->remove   = &list_access;
    self->find     = &list_find;
    self->contains = &list_contains;
    return self;
}

void list_del(list * self) {
    switch (self->ds) {
        case LinkedList: llist_del(self->list); break;
        case ArrayList:  alist_del(self->list); break;
        default: self->list = NULL; break;
    }
    free(self);
}

int list_append(list * self, item element) {
    int rv;
    switch( self->ds ) {
        case LinkedList: rv = llist_append(self->list, element); break;
        case ArrayList:  rv = alist_append(self->list, element); break;
        default: rv = -1; break;
    }
    return rv;
}

int list_prepend(list * self, item element) {
    int rv;
    switch( self->ds ) {
        case LinkedList: rv = llist_prepend(self->list, element); break;
        case ArrayList:  rv = alist_prepend(self->list, element); break;
        default: break;
    }
    return rv;
}

int list_insert(list * self, int index, item element) {
    int rv;
    switch( self->ds ) {
        case LinkedList: llist_insert(self->list, index, element); break;
        case ArrayList: alist_insert(self->list, index, element); break;
        default: break;
    }
    return rv;
}

item list_access(list * self, int index) {
    item  rv;
    switch( self->ds ) {
        case LinkedList: rv = llist_access(self->list, index); break;
        case ArrayList: rv = alist_access(self->list, index); break;
        default: break;
    }
    return rv;
}

item list_remove(list * self, int index) {
    item  rv;
    switch( self->ds ) {
        case LinkedList: rv = llist_remove(self->list, index); break;
        case ArrayList: rv = alist_remove(self->list, index); break;
        default: break;
    }
    return rv;
}

item list_update(list * self, int index, item element) {
    item  rv;
    switch( self->ds ) {
        case LinkedList: rv = llist_update(self->list, index, element); break;
        case ArrayList: rv = alist_update(self->list, index, element); break;
        default: break;
    }
    return rv;

}

int list_find(list * self, item element) {
    int rv;
    switch( self->ds ) {
        case LinkedList: rv = llist_find(self->list, element); break;
        case ArrayList: rv = alist_find(self->list, element); break;
        default: return -1; break;
    }
    return rv;
}

bool list_contains(list * self, item element) {
    return list_find(self, element) >= 0; 
}

//
// Implementations

// llist

llist * llist_new() {
    llist * self = (llist *) malloc(sizeof(llist)); 
    self->size = 0;
    self->start = self->end = NULL;
    return self;
}

void llist_del(llist * self) {
    free(self);
}

int  llist_append(llist * self, item element);
int  llist_prepend(llist * self, item element);
int  llist_insert(llist * self, int index, item element);
item llist_access(llist * self, int index);
item llist_remove(llist * self, int index);
item llist_update(llist * self, int index, item element);
int  llist_find(llist * self, item element);
bool llist_contains(llist * self, item element);

// alist

alist * alist_new() {
    alist * self = (alist *) malloc(sizeof(alist));
    self->array = (item_p) malloc(sizeof(item) * DEFAULTALISTSIZE);
    self->size = 0;
    self->capacity = DEFAULTALISTSIZE;
    return self;
}

void alist_del(alist * self) {
    free(self->array);
    free(self);
}

int  alist_append(alist * self, item element);
int  alist_prepend(alist * self, item element);
int  alist_insert(alist * self, int index, item element);
item alist_access(alist * self, int index);
item alist_remove(alist * self, int index);
item alist_update(alist * self, int index, item element);
int  alist_find(alist * self, item element);
bool alist_contains(alist * self, item element);
