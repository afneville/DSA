#include <stdio.h>
#include <stdlib.h>
#include "../inc/item.h"

int main() {
    int int_val = 4;
    float flt_val = 3.2;
    char char_val = 't';
    char str_val[] = "Hello!";
    item ** array = (item **) malloc(sizeof(item *) * 4);
    array[0] = new_item(Integer, &int_val);
    array[1] = new_item(Float, &flt_val);
    array[2] = new_item(Character, &char_val);
    array[3] = new_item(String, &str_val);
    printf("[");
    for (int i = 0; i < 4; i++) {
        print_item(array[i]);
        printf(", ");
    }
    printf("\b\b]\n");
    return 0;
}
