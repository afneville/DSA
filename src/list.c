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

int llist_append(llist * self, item element) {
    llist_node * new_node = (llist_node *) malloc(sizeof(llist_node));
    new_node->next = NULL;
    new_node->val = element;
    if (self->size == 0) {
        new_node->prev = NULL;
        self->start = new_node;
    } else {
        new_node->prev = self->end;
        self->end->next = new_node;
    }
    self->end = new_node;
    int index = (self->size)++;
    return index;
}

int llist_prepend(llist * self, item element) {
    llist_node * new_node = (llist_node *) malloc(sizeof(llist_node));
    new_node->val = element;
    new_node->prev = NULL;
    if (self->size == 0) {
        new_node->next = NULL;
        self->end = new_node;
    } 
    else {
        new_node->next = self->start;
        self->start->prev = new_node;
    }
    self->start = new_node;
    ++(self->size);
    return 0;
}

int llist_insert(llist * self, int index, item element) {
    if (index >= self->size) return llist_append(self, element);
    if (index < 0) return -1; 
    if (index == 0) return llist_prepend(self, element);

    llist_node * new_node = (llist_node *) malloc(sizeof(llist_node));
    new_node->val = element;
    int i = 0;
    llist_node * ptr = self->start;
    while (i++ < index - 1) {
        ptr = ptr->next;
    }
    new_node->prev = ptr;
    new_node->next = ptr->next;
    new_node->next->prev = new_node;
    ptr->next = new_node;
    ++(self->size);
    return index;
}

item llist_access(llist * self, int index) {
    if (index < 0 || index >= self->size) { 
        fprintf(stderr, "\nList index out of range.\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    llist_node * ptr = self->start;
    while (i++ < index) {
        ptr = ptr->next;
    }
    return ptr->val;
}

item llist_remove(llist * self, int index) {
    if (index < 0 || index >= self->size) { 
        fprintf(stderr, "\nList index out of range.\n");
        exit(EXIT_FAILURE);
    }
    llist_node * ptr;
    item rv;
    if (index == 0) {
        ptr = self->start;
        if (self->size == 1) {
            self->start = NULL;
            self->end = NULL;
        } else {
            self->start = self->start->next;
            self->start->prev = NULL;
        }
    } else if (index == self->size -1) {
        ptr = self->end;
        self->end = self->end->prev;
        self->end->next = NULL;
    } else {
        int i = 0;
        ptr = self->start;
        while (i++ < index) {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    rv = ptr->val;
    free(ptr);
    --(self->size);
    return rv;
}

item llist_update(llist * self, int index, item element) {
    if (index < 0 || index >= self->size) { 
        fprintf(stderr, "\nList index out of range.\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    llist_node * ptr = self->start;
    while (i++ < index) {
        ptr = ptr->next;
    }
    ptr->val = element;
    return ptr->val;
}

int llist_find(llist * self, item element) {
    int rv = -1, i = 0;
    llist_node * ptr = self->start;
    while(ptr) {
        if (item_compare(&ptr->val, &element)) {
            rv = i;
            break;
        }
        i++;
        ptr = ptr->next;
    }
    return rv;
};

bool llist_contains(llist * self, item element) {
    return llist_find(self, element) >= 0;
}

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

int  alist_append(alist * self, item element) { return -1; };
int  alist_prepend(alist * self, item element){ return -1; };
int  alist_insert(alist * self, int index, item element){ return -1; };
item alist_access(alist * self, int index) {return item_new(Integer, -1);};
item alist_remove(alist * self, int index) {return item_new(Integer, -1);};
item alist_update(alist * self, int index, item element) {return item_new(Integer, -1);};
int  alist_find(alist * self, item element){ return -1; };
bool alist_contains(alist * self, item element){ return 0; };
