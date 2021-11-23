#include <stdio.h>
#include <stdlib.h>
#include "../include/object.h"
#include "../include/llist.h"
#include "../include/dict.h"
#include "../include/logger.h"
#include "../include/primes.h"


int main() {

    open_logfile();
    gen_primes();

    char keys[20][6] = {
        "key00",
        "key01",
        "key02",
        "key03",
        "key04",
        "key05",
        "key06",
        "key07",
        "key08",
        "key09",
        "key10",
        "key11",
        "key12",
        "key13",
        "key14",
        "key15",
        "key16",
        "key17",
        "key18",
        "key19"
    };

    // printf("%d\n", primes_array[3]);

    dict * test_dict = create_dictionary(DirectChaining, Prime, primes_array[4], 4);

    // insert data
    for (int i = 0; i < 20; i++) {
        int j = i;
        object * insert_data = create_object(Integer, &j);
        int rc = insert_dictionary(test_dict, keys[i], insert_data, 0);
    }

    // search dictionary
    for (int i = 0; i < 20; i++) {
        ds_node * retrieved = search_dictionary(test_dict, keys[i]);
        if (retrieved){
            printf("%s => ", keys[i]);
            repr(retrieved->record);
            printf("\n");
        } else {
            printf("key not found\n");
        }
    }

    printf("checkpoint 1\n");
    close_logfile();
    printf("checkpoint 2\n");
    return 0;

}
