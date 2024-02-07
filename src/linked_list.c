#include <stdio.h>
#include <stdlib.h>
#include "../inc/linked_list.h"

list_node * create_list_node() {

    list_node * new_node_p = (list_node *) malloc(sizeof(list_node));
    new_node_p->value = NULL;
    new_node_p->next = NULL;

    return new_node_p;

}


linked_list * create_linked_list() {

    linked_list * new_list_p = (linked_list *) malloc(sizeof(linked_list));
    new_list_p->start_p = NULL;
    return new_list_p;

}

void append_list(linked_list * list_p, int value) {

    if (list_p->start_p == NULL) {

        list_p->start_p = create_list_node();
        list_p->start_p->value = value;

    } else {

        list_node * node_p = list_p->start_p;

        while (node_p->next) {

            node_p = node_p->next;

        }

        node_p->next = create_list_node();
        node_p->next->value = value;

    }

}

void traverse_list(linked_list * list_p) {

    if (list_p->start_p != NULL) {

        list_node * node_p = list_p->start_p;

        while (node_p->next) {

            printf("%d\n", node_p->value);
            node_p = node_p->next;
        }

        printf("%d\n", node_p->value);

    }

}

void destroy_list(linked_list * list_p) {

    if (list_p->start_p == NULL) {

        list_node * node_p = list_p->start_p;

        while (node_p->next) {

            list_node * tmp = node_p;
            node_p = node_p->next;
            free(tmp);
        }

        free(node_p);

    }

    free(list_p);

}
