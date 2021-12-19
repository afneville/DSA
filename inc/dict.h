#ifndef dict_H
#define dict_H
#include "./object.h"

#define INITIAL_BUCKET_COUNT 8
#define NUM_PRIMES 100

typedef enum collision_resolution_method_E {
    OpenAddressing,
    DirectChaining
} resolve;

typedef enum resize_method_E {
    Prime,
    Double
} resize;

typedef struct dict_T {
    int size;
    int num_entries;
    node ** array;
    resolve collision_approach;
    resize resize_approach;
    int primes_array_index;
} dict;

extern dict * tmp_dict;

dict * new_dict(resolve collision_approach,
        resize resize_approach, int size, int primes_array_index);

void del_dict(dict * old_dict);
node * search_dict(dict * self, char * key);
void rm_dict(dict * self, char * key);
int ins_dict(dict * self, char * key, object * insert_data, int dynamic);

float calc_load_factor(dict * self);
void maintain_dict(dict * self);

#endif // dict_H
