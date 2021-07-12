#ifndef linked_list_H
#define linked_list_H

typedef struct list_node_T {

    int value;
    struct list_node_T * next;

} list_node;

typedef struct linked_list_T {

    list_node * start_p;

} linked_list;

list_node * create_list_node();
linked_list * create_linked_list();
void append_list(linked_list * list_p, int value);
void traverse_list(linked_list * list_p);
void destroy_list(linked_list * list_p);

#endif // !linked_list_H
