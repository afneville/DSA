#ifndef LIST_H
#define LIST_H
#define DEFAULTALISTSIZE 4
#include "./item.h"
#include <stdbool.h>

typedef enum list_type_E_ list_impl;
typedef struct list_T_ list;
typedef struct llist_node_T_ llist_node;
typedef struct llist_T_ llist;
typedef struct alist_T_ alist;

enum list_type_E_ {
    LinkedList,
    ArrayList
};

struct list_T_ {
   list_impl ds;
   void * list;
   int  (* append)   (struct list_T_ * self, item element);
   int  (* prepend)  (struct list_T_ * self, item element);
   int  (* insert)   (struct list_T_ * self, int index, item element);
   item (* access)   (struct list_T_ * self, int index);
   item (* remove)   (struct list_T_ * self, int index);
   item (* update)   (struct list_T_ * self, int index, item element);
   int  (* find)     (struct list_T_ * self, item element);
   bool (* contains) (struct list_T_ * self, item element);
};

typedef struct llist_node_T_ {
    item val;
    struct llist_node_T_ * next;
    struct llist_node_T_ * prev;
} llist_node;

typedef struct llist_T_ {
    int size;
    llist_node * start;
    llist_node * end;
} llist;

struct alist_T_ {
    item_p array;
    int size;
    int capacity;
};

// ADT
list * list_new(list_impl ds);
void list_del(list * self);
int  list_append(list * self, item element);
int  list_prepend(list * self, item element);
int  list_insert(list * self, int index, item element);
item list_access(list * self, int index);
item list_remove(list * self, int index);
item list_update(list * self, int index, item element);
int  list_find(list * self, item element);
bool list_contains(list * self, item element);

//linked list
llist * llist_new();
void llist_del(llist * self);
int  llist_append(llist * self, item element);
int  llist_prepend(llist * self, item element);
int  llist_insert(llist * self, int index, item element);
item llist_access(llist * self, int index);
item llist_remove(llist * self, int index);
item llist_update(llist * self, int index, item element);
int  llist_find(llist * self, item element);
bool llist_contains(llist * self, item element);

// array list
alist * alist_new();
void alist_del(alist * self);
int  alist_append(alist * self, item element);
int  alist_prepend(alist * self, item element);
int  alist_insert(alist * self, int index, item element);
item alist_access(alist * self, int index);
item alist_remove(alist * self, int index);
item alist_update(alist * self, int index, item element);
int  alist_find(alist * self, item element);
bool alist_contains(alist * self, item element);

#endif // LIST_H
