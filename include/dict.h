#ifndef dict_H
#define dict_H
#include "./object.h"

#define INITIAL_BUCKET_COUNT 8
#define NUM_PRIMES 100

typedef enum collision_resolution_method_E {
    OpenAddressing,
    DirectChaining
} collision_resolution_method;

typedef enum resize_method_E {
    Prime,
    Double
} resize_method;

typedef struct dict_T {
    int size;
    int num_entries;
    ds_node ** array;
    collision_resolution_method collision_approach;
    resize_method resize_approach;
    int primes_array_index;
} dict;

extern dict * tmp_dict;

dict * create_dictionary(collision_resolution_method collision_approach,
        resize_method resize_approach, int size, int primes_array_index);

ds_node * search_dictionary(dict * self, char * key);
void destroy_dictionary(dict * old_dict);
int insert_dictionary(dict * self, char * key, object * insert_data, int dynamic);

float calc_load_factor(dict * self);
void maintain_dict(dict * self);

#endif // dict_H
