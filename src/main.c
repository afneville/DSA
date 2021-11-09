#include <stdio.h>
#include <stdlib.h>
#include "includes/object.h"


int main() {

    int a = 5;
    char arr[6] = "hello\0";
    object * object_one = new_object(Integer, &a);
    object * object_two = new_object(String, arr);

    printf("%d\n", object_one->data.integer_data);
    printf("%c\n", object_two->data.string_data[0]);
    printf("%s\n", object_two->data.string_data);
    return 0;
}
