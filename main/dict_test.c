#include "../inc/dict.h"
#include <stdio.h>

int main() {
    dict *map = new_dict(DirectChaining, Prime, 10, 1);
    char *keys[] = { "abc", "def", "ghi" };
    int values[] = {1, 2, 3};
    ins_dict(map, keys[0], new_obj(Integer, &values[0]), 0);
    ins_dict(map, keys[1], new_obj(Integer, &values[1]), 0);
    ins_dict(map, keys[2], new_obj(Integer, &values[2]), 0);
    node *result = search_dict(map, keys[2]);
    if (result) {
        repr_obj(result->record);
        printf("\n");
    }
}
