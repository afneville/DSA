#include <stdio.h>
#include <stdlib.h>
#include "../inc/item.h"
#define LOCALLEN 9

int main() {
    item ** a = (item **) malloc(sizeof(item *) * LOCALLEN);
    int i = 0;
    a[i++] = new_item(Integer, 4);
    a[i++] = new_item(Integer, 4);
    a[i++] = new_item(Integer, 5);
    a[i++] = new_item(Float, 3.2);
    a[i++] = new_item(Character, 't');
    a[i++] = new_item(String, "Hello!");
    a[i++] = new_item(String, "Hello!");
    a[i++] = new_item(String, "Hi!");
    a[i++] = new_item(String, "This is quite a long string.");

    printf("%d\n", compare_item(a[5], a[6]));
    printf("%d\n", compare_item(a[5], a[7]));
    printf("%d\n", compare_item(a[0], a[1]));
    printf("%d\n\n", compare_item(a[0], a[2]));
    printf("%s\n", repr_item(a[8]));

    printf("[");
    for (int i = 0; i < LOCALLEN; i++) {
        print_item(a[i]);
        del_item(a[i]);
        printf(", ");
    }
    printf("\b\b]\n");
    free(a);

    return 0;
}
