#include <stdio.h>
#include <stdlib.h>
#include "../include/object.h"
#include "../include/list.h"
#include "../include/dict.h"
#include "../include/logger.h"
#include "../include/primes.h"

int main() {
    open_logfile();
    gen_primes();

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

    close_logfile();
    return 0;
}
