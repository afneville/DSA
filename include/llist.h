#ifndef llist_H
#define llist_H

#include "./object.h"
#include "./dict.h"

extern int llist_flag;

node * traverse_llist(node * current, node * tmp, node * (* callback)(node * current_element, node * tmp));

// callbacks
node * append_llist(node * current, node * tmp);
node * append_llist_unique(node * current, node * tmp);
node * print_callback(node * current, node * tmp);
node * search_callback(node * current, node * tmp);
node * ins_callback(node * current, node * tmp);

#endif // llist_H
