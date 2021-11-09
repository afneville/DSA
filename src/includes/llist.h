#ifndef llist_H
#define llist_H

#include "./object.h"
#include "./dict.h"

typedef struct llstart_T {
   ds_node * start; 
   int elements;
} llstart;

llstart create_llstart();
void append_list(object * new_data);
void traverse(ds_node * current, ds_node * tmp, void (* callback)(object * current_element));

#endif // llist_H
