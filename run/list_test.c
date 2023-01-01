#include <stdio.h>
#include "../inc/item.h"
#include "../inc/list.h"

void print_list(list * L) {
    item tmp;
    printf("[ ");
    for (int i = 0; i < L->size(L); i++) {
        tmp = L->access(L, i);
        item_print(&tmp);
        printf(", ");
    }
    printf("\b\b ]\n");
}

int main() {
    
    list List = * list_new(LinkedList);
    list * l = list_new(LinkedList);

    List.append(l, item_new(Integer, 4));
    List.append(l, item_new(Integer, 5));
    List.append(l, item_new(Integer, 6));
    List.append(l, item_new(Integer, 7));
    print_list(l);

    return 0;
}
