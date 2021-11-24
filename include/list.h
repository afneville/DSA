#ifndef llist_H
#define llist_H

#include "./object.h"
#include "./dict.h"

extern int llist_flag;

typedef enum direction_E {
    Forwards,
    Backwards
} direction;

typedef struct list_T {
    node * head; 
    node * tail;
    int num_elements;
} list;

list * new_list();
void del_list(list * list_p);

void push(list * list_p, object * obj_p);
object * peek(list * list_p);
object * pop(list * list_p);
void enqueue(list * list_p, object * obj_p);
object * dequeue(list * list_p);

node * traverse_list(node * current, node * tmp, direction dir, node * (* callback)(node * current_element, node * tmp));

// callbacks
node * append_list(node * current, node * tmp);
node * append_list_unique_key(node * current, node * tmp);
node * del_item_by_key(node * current, node * tmp);
node * print_callback(node * current, node * tmp);
node * search_callback(node * current, node * tmp);
node * ins_callback(node * current, node * tmp);

#endif // llist_H
