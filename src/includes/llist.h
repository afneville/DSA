#ifndef llist_H
#define llist_H

#include "./object.h"
#include "./dict.h"

ds_node * traverse(ds_node * current, ds_node * tmp, ds_node * (* callback)(ds_node * current_element, ds_node * tmp));

// callbacks
ds_node * append(ds_node * current, ds_node * tmp);
ds_node * print(ds_node * current, ds_node * tmp);
ds_node * search(ds_node * current, ds_node * tmp);

#endif // llist_H
