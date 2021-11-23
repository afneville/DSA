#include <string.h>
#include <stdlib.h>
#include "../include/llist.h"
#include "../include/dict.h"

int llist_flag = 0;

node * traverse_llist(node * current, node * tmp, node * (* callback)(node * current_element, node * tmp)) {

    llist_flag = 0;
    if (!current) return NULL;
    node * next = current->next;
    node * local_ret_v;
    if(!(local_ret_v = callback(current, tmp))) {
        local_ret_v = traverse_llist(next, tmp, callback);
    }
    return local_ret_v;

}

node * append_llist(node * current, node * tmp) {
    if (!current->next) {
        current->next = tmp;
        return tmp;
    } else {
        return NULL;
    }
}


node * append_llist_unique(node * current, node * tmp) {
    if (strcmp(current->key, tmp->key) == 0){
        llist_flag = -1;
        return tmp;
    }
    if (!current->next) {
        llist_flag = 0;
        current->next = tmp;
        return tmp;
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
