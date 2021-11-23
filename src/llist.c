#include <string.h>
#include <stdlib.h>
#include "../include/llist.h"
#include "../include/dict.h"

int llist_flag = 0;

ds_node * traverse_llist(ds_node * current, ds_node * tmp, ds_node * (* callback)(ds_node * current_element, ds_node * tmp)) {

    llist_flag = 0;
    if (!current) return NULL;
    ds_node * next = current->next;
    ds_node * local_ret_v;
    if(!(local_ret_v = callback(current, tmp))) {
        local_ret_v = traverse_llist(next, tmp, callback);
    }
    return local_ret_v;

}

ds_node * append_llist(ds_node * current, ds_node * tmp) {
    if (!current->next) {
        current->next = tmp;
        return tmp;
    } else {
        return NULL;
    }
}


ds_node * append_llist_unique(ds_node * current, ds_node * tmp) {
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

ds_node * print_callback(ds_node * current, ds_node * tmp) {
    if(current->record)
        repr(current->record);
    return NULL;
}

ds_node * search_callback(ds_node * current, ds_node * tmp) {
    if(strcmp(current->key, tmp->key) == 0) {
        llist_flag = 0;
        return current;
    } else {
        return NULL;
    }
}

ds_node * insert_callback(ds_node * current, ds_node * tmp) {
    insert_dictionary(tmp_dict, current->key, current->record, 0);
    // free(current);
    return NULL;
}
