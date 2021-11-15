#ifndef dict_H
#define dict_H
#include "./object.h"

#define INITIAL_BUCKET_COUNT 8


typedef struct dict_T {
    int num_buckets;
    int num_entries;
    ds_node ** buckets;
} dict;

dict * create_dictionary();

ds_node * search_dictionary(dict * existing_dict, char * key);
int insert_dictionary(dict * existing_dict, char * key, object * insert_data);
void resize_dictionary(dict * existing_dict);
void destroy_dictionary(dict * old_dict);

#endif // dict_H
