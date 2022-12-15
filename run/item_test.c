#include <stdio.h>
#include <stdlib.h>
#include "../inc/item.h"

int main() {
    item ** array = (item **) malloc(sizeof(item *) * 4);
    array[0] = new_item(Integer, 4);
    array[1] = new_item(Float, 3.2);
    array[2] = new_item(Character, 't');
    array[3] = new_item(String, "Hello!");
    printf("[");
    for (int i = 0; i < 4; i++) {
        print_item(array[i]);
        free(array[i]);
        printf(", ");
    }
    printf("\b\b]\n");
    free(array);
    return 0;
}
