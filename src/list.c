#include <string.h>
#include <stdlib.h>
#include "../inc/list.h"
#include "../inc/dict.h"
#include "../inc/object.h"

int llist_flag = 0;

list * new_list() {
    list * list_p = (list *) malloc(sizeof(list));
    list_p->head = list_p->tail = NULL;
    list_p->num_elements = 0;
    return list_p;
}
void del_list(list * list_p) {
    if (list_p)
        free(list_p);
};

void push(list * list_p, object * obj_p) {
    node * node_p = new_node();
    node_p->record = obj_p;
    if (!list_p->head) {
        list_p->head = list_p->tail = node_p;
    } else {
        list_p->tail->next = node_p;
        node_p->prev = list_p->tail;
        node_p->next = NULL;
        list_p->tail = node_p;
    }
    list_p->num_elements++;
}

object * pop(list * list_p) {
    if (list_p->tail && list_p->head == list_p->tail) {
        node * rv = list_p->tail;
        list_p->head = list_p->tail = NULL;
        list_p->num_elements--;
        return rv->record;
    } else if (list_p->tail) {
        node * rv = list_p->tail;
        list_p->tail = rv->prev;
        list_p->num_elements--;
        return rv->record;
    } else {
        return NULL;
    }
}

void enqueue(list * list_p, object * obj_p) {
    push(list_p, obj_p);
};

object * dequeue(list * list_p) {
    if (list_p->head && list_p->head == list_p->tail) {
        node * rv = list_p->head;
        list_p->head = list_p->tail = NULL;
        list_p->num_elements--;
        return rv->record;
    } else if (list_p->head) {
        node * rv = list_p->head;
        list_p->head = rv->next;
        list_p->num_elements--;
        return rv->record;
    } else {
        return NULL;
    }
}

node * traverse_list(node * current, node * tmp, direction dir, node * (* callback)(node * current_element, node * tmp)) {
    llist_flag = 0;
    if (!current) return NULL;
    node * next;
    node * rv;
    if (dir == Forwards) {
        next = current->next;
    } else {
        next = current->prev;
    }
    if(!(rv = callback(current, tmp))) {
        rv = traverse_list(next, tmp, dir, callback);
    }
    return rv;
}

node * append_list(node * current, node * tmp) {
    if (!current->next) {
        current->next = tmp;
        tmp->prev = current;
        return tmp;
    } else {
        return NULL;
    }
}

node * append_list_unique_key(node * current, node * tmp) {
    if (strcmp(current->key, tmp->key) == 0){
        llist_flag = -1;
        return tmp;
    }
    if (!current->next) {
        llist_flag = 0;
        current->next = tmp;
        tmp->prev = current;
        return tmp;
    } else {
        return NULL;
    }
}

node * del_item_by_key(node * current, node * tmp) {
    if (strcmp(current->key, tmp->key) == 0){
        node * rv = current->next;
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        free(current);
        return rv;
    } else {
        return NULL;
    }
}

node * print_callback(node * current, node * tmp) {
    if(current->record)
        repr_obj(current->record);
    return NULL;
}

node * search_callback(node * current, node * tmp) {
    if(strcmp(current->key, tmp->key) == 0) {
        llist_flag = 0;
        return current;
    } else {
        return NULL;
    }
}

node * ins_dict_callback(node * current, node * tmp) {
    ins_dict(tmp_dict, current->key, current->record, 0);
    return NULL;
}


node * del_callback(node * current, node * tmp) {
    del_obj(current->record);
    del_node(current);
    return NULL;
}
