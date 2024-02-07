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
    List.append(l, item_new(Character, 'a'));
    List.append(l, item_new(Double, 14.2));
    List.append(l, item_new(String, "Hello"));
    print_list(l);

    return 0;
}
