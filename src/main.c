#include <stdio.h>
#include <stdlib.h>
#include "./includes/object.h"
#include "./includes/llist.h"
#include "./includes/dict.h"
#include "./includes/logger.h"


int main() {

    open_logfile();

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
        object * insert_data = create_object(Integer, &j);
        int rc = insert_dictionary(test_dict, keys[i], insert_data);
    }

    for (int i = 0; i < 10; i++) {
        ds_node * retrieved = search_dictionary(test_dict, keys[i]);
        if (retrieved){
            represent(retrieved->record);
        } else {
            printf("key not found\n");
        }
    }

    close_logfile();
    return 0;

}
