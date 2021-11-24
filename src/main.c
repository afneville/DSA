#include <stdio.h>
#include <stdlib.h>
#include "../include/object.h"
#include "../include/list.h"
#include "../include/dict.h"
#include "../include/logger.h"
#include "../include/primes.h"


void test_dict_implementation() {

    char keys[20][6] = {
        "key00", "key01", "key02", "key03",
        "key04", "key05", "key06", "key07",
        "key08", "key09", "key10", "key11",
        "key12", "key13", "key14", "key15",
        "key16", "key17", "key18", "key19"
    };

    dict * test_dict = new_dict(OpenAddressing, Prime, primes_array[4], 4);

    // insert data
    for (int i = 0; i < 20; i++) {
        int j = i;
        object * insert_data = new_obj(Integer, &j);
        int rc = ins_dict(test_dict, keys[i], insert_data, 1);
    }

    // search dictionary
    for (int i = 0; i < 20; i++) {
        node * retrieved = search_dict(test_dict, keys[i]);
        if (retrieved){
            printf("%s => ", keys[i]);
            repr_obj(retrieved->record);
            printf("\n");
        } else {
            printf("key not found\n");
        }
    }

}

void test_list_implementation() {

    list * test_list = new_list();

    for (int i = 0; i < 20; i++) {
        int j = i;
        object * insert_data = new_obj(Integer, &j);
        push(test_list, insert_data);
    }
    repr_obj(dequeue(test_list));
    printf("\n");
    for (int i = 0; i < 20; i++) {
        repr_obj(pop(test_list));
        printf(" -> ");
    }
    printf("END\n");
    del_list(test_list);
}

int main() {
    open_logfile();
    gen_primes();
    // test_dict_implementation();
    test_list_implementation();
    close_logfile();
    return 0;
}
