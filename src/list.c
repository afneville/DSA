#include <string.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/dict.h"

int llist_flag = 0;

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
        current->prev->next = current->next;
        current->next->prev = current->prev;
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

node * ins_callback(node * current, node * tmp) {
    ins_dict(tmp_dict, current->key, current->record, 0);
    // free(current);
    return NULL;
}
