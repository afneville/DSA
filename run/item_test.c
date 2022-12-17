#include <stdio.h>
#include <stdlib.h>
#include "../inc/item.h"

int main() {
    item ** item_p_arr = (item **) malloc(sizeof(item *) * 4);
    item_p_arr[0] = new_item_p(Integer, 4);
    item_p_arr[1] = new_item_p(Float, 3.2);
    item_p_arr[2] = new_item_p(Character, 't');
    item_p_arr[3] = new_item_p(String, "Hello!");
    printf("[");
    for (int i = 0; i < 4; i++) {
        print_item(item_p_arr[i]);
        del_item_p(item_p_arr[i]);
        printf(", ");
    }
    printf("\b\b]\n");
    free(item_p_arr);

    item * item_arr = (item *) malloc(sizeof(item) * 4);
    item_arr[0] = (item) {.val.int_val = 5, .type = Integer};
    item_arr[1] = (item) {.val.flt_val = 8.9, .type = Float};
    item_arr[2] = init_item(Character, 's');
    item_arr[3] = init_item(String, "Goodbye!");
    printf("[");
    for (int i = 0; i < 4; i++) {
        print_item(&item_arr[i]);
        printf(", ");
    }
    printf("\b\b]\n");
    free(item_arr);

    return 0;
}
