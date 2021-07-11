#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_T {

    int value;
    struct list_node_T * next;

} list_node;

list_node * create_node() {

    list_node * new_node_p = (list_node *) malloc(sizeof(list_node));
    new_node_p->value = NULL;
    new_node_p->next = NULL;

    return new_node_p;

}

typedef struct linked_list_T {

    list_node * start_p;

} linked_list;

linked_list * create_linked_list() {

    linked_list * new_list_p = (linked_list *) malloc(sizeof(linked_list));
    new_list_p->start_p = NULL;
    return new_list_p;

}

void append(linked_list * list_p, int value) {

    if (list_p->start_p == NULL) {

        list_p->start_p = create_node();
        list_p->start_p->value = value;

    } else {

        list_node * node_p = list_p->start_p;

        while (node_p->next) {

            node_p = node_p->next;

        }

        node_p->next = create_node();
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

int main (int argc, char *argv[]) {

    linked_list * list_p = create_linked_list();

    append(list_p, 3);
    append(list_p, 2);
    append(list_p, 1);

    traverse_list(list_p);
    destroy_list(list_p);

    return 0;

}
