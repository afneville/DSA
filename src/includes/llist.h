#ifndef llist_H
#define llist_H

#include "./object.h"
#include "./dict.h"

ds_node * traverse_llist(ds_node * current, ds_node * tmp, ds_node * (* callback)(ds_node * current_element, ds_node * tmp));

// callbacks
ds_node * append_llist(ds_node * current, ds_node * tmp);
ds_node * print_callback(ds_node * current, ds_node * tmp);
ds_node * search_callback(ds_node * current, ds_node * tmp);

#endif // llist_H
