#include <stdio.h>
#include "../inc/item.h"
#include "../inc/list.h"

void print_llist(list * L) {
    llist * LL = (llist *) L->list;
    item tmp;
    printf("[");
    for (int i = 0; i < LL->size; i ++) {
        tmp = list_access(L, i);
        item_print(&tmp);
        printf(", ");
    }
    if (LL->size >= 1) printf("\b\b");
    printf("]\n");
}

int main() {
    
    list * L = list_new(LinkedList);
    print_llist(L);
    list_append(L, item_new(Integer, 2));
    print_llist(L);
    list_append(L, item_new(Integer, 5));
    print_llist(L);
    list_append(L, item_new(Integer, 6));
    print_llist(L);
    list_prepend(L, item_new(Integer, 7));
    print_llist(L);
    list_insert(L, 2, item_new(Integer, 7));
    print_llist(L);

    return 0;
}
