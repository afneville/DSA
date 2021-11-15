#include <stdio.h>
#include <stdlib.h>
#include "./includes/object.h"
#include "./includes/llist.h"
#include "./includes/dict.h"


int main() {

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
