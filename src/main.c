#include <stdio.h>
#include <stdlib.h>
#include "../includes/object.h"
#include "../includes/llist.h"
#include "../includes/dict.h"


int main() {

    // create "objects"

/*     printf("%d\n", object_one->data.integer_data); */
/*     printf("%f\n", object_two->data.decimal_data); */
/*     printf("%c\n", object_three->data.string_data[0]); */
/*     printf("%s\n", object_three->data.string_data); */
/*  */
/*     ds_node * node_one = create_ds_node(object_one, NULL); */
/*     ds_node * node_two = create_ds_node(object_two, NULL); */
/*     ds_node * node_three = create_ds_node(object_three, NULL); */
/*  */
/*     traverse(node_one, node_two, append); */
/*     traverse(node_one, node_three, append); */
/*  */
/*     traverse(node_one, NULL, print); */

    char keys[10][5] = {
        "key0",
        "key1",
        "key2",
        "key3",
        "key4",
        "key5",
        "key6",
        "key7",
        "key8",
        "key9"
    };

    dict * test_dict = create_dictionary();

    // insert data
    for (int i = 0; i < 10; i++) {
        int j = i;
        object * insert_data = new_object(Integer, &j);
        int rc = insert_dictionary(test_dict, keys[i], insert_data);
        if (rc) {
            printf("inserted\n");
        } else {
            printf("not inserted\n");
        }
    }
    for (int i = 0; i < 10; i++) {
        ds_node * retrieved = search_dictionary(test_dict, keys[i]);
        if (retrieved){
            represent(retrieved->record);
        }
    }

    return 0;

}
