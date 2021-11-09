#include <stdio.h>
#include <stdlib.h>
#include "includes/object.h"
#include "includes/llist.h"
#include "includes/dict.h"


int main() {

    // create "objects"
    int a = 5;
    float b = 14.3;
    char c[6] = "hello\0";
    object * object_one = new_object(Integer, &a);
    object * object_two = new_object(Decimal, &b);
    object * object_three = new_object(String, &c);

    printf("%d\n", object_one->data.integer_data);
    printf("%f\n", object_two->data.decimal_data);
    printf("%c\n", object_three->data.string_data[0]);
    printf("%s\n", object_three->data.string_data);

    ds_node * node_one = create_ds_node(object_one, NULL);
    ds_node * node_two = create_ds_node(object_two, NULL);
    ds_node * node_three = create_ds_node(object_three, NULL);

    traverse(node_one, node_two, append);
    traverse(node_one, node_three, append);

    traverse(node_one, NULL, print);

    return 0;

}
