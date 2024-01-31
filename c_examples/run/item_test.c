#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <item.h>
#define LOCALLEN 9

int main() {
    item_p * a = (item_p *) malloc(sizeof(item_p) * LOCALLEN);
    int i = 0;
    a[i++] = item_new_p(Integer, 4);
    a[i++] = item_new_p(Integer, 4);
    a[i++] = item_new_p(Integer, 5);
    a[i++] = item_new_p(Float, 3.2);
    a[i++] = item_new_p(Character, 't');
    a[i++] = item_new_p(String, "Hello!");
    a[i++] = item_new_p(String, "Hello!");
    a[i++] = item_new_p(String, "Hi!");
    a[i++] = item_new_p(String, "This is quite a long string.");

    printf("%d\n", item_compare(a[5], a[6]));
    printf("%d\n", item_compare(a[5], a[7]));
    printf("%d\n", item_compare(a[0], a[1]));
    printf("%d\n\n", item_compare(a[0], a[2]));
    printf("%s\n", item_repr(a[8]));
    printf("%lu\n", item_hash(a[0]));
    printf("%lu\n", item_hash(a[1]));
    printf("%lu\n", item_hash(a[4]));

    printf("[");
    for (int i = 0; i < LOCALLEN; i++) {
        item_print(a[i]);
        item_del_p(a[i]);
        printf(", ");
    }
    printf("\b\b]\n");
    free(a);

    item b = item_new(Integer, 1234);
    item_print(&b);
    char * string1 = item_repr(&b); // 1234
    item_modify(&b, Character, 'T');
    char * string2 = item_repr(&b); // 'T'
    item_p c = item_clone_p(&b);
    printf("\n%s\n", item_repr(c));
    printf("%s %s\n", string1, string2);
    free(string1);
    free(string2);
    free(c);

    return 0;
}
