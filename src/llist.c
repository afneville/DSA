#include <string.h>
#include <stdlib.h>
#include "../includes/llist.h"

ds_node * traverse(ds_node * current, ds_node * tmp, ds_node * (* callback)(ds_node * current_element, ds_node * tmp)) {

    if (!current) return NULL;
    ds_node * local_ret_v;
    if(!(local_ret_v = callback(current, tmp))) {
        local_ret_v = traverse(current->next, tmp, callback);
    }
    return local_ret_v;

}

ds_node * append(ds_node * current, ds_node * tmp) {
    if (!current->next) {
        current->next = tmp;
        return tmp;
    } else {
        return NULL;
    }
}

ds_node * print(ds_node * current, ds_node * tmp) {
    if(current->record)
        represent(current->record);
    return NULL;
}

ds_node * search(ds_node * current, ds_node * tmp) {
    if(strcmp(current->key, tmp->key)) {
        return current;
    } else {
        return NULL;
    }
}
