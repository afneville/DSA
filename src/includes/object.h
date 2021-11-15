#ifndef object_H
#define object_H
    
typedef union object_data_U {
    double decimal_data;
    int integer_data;
    char * string_data;
} object_data;

typedef enum object_type_E {
    Integer,
    Decimal,
    String
} object_type;

typedef struct object_T {
    object_data data;
    object_type type;
} object;

typedef struct ds_node_T {
    object * record;
    struct ds_node_T * next;
    char * key;
    unsigned long hash;
    int buried_nodes;
    struct ds_node_T * left;
    struct ds_node_T * right;
} ds_node;

object * new_object(object_type type, void * ptr);
void represent(object * ptr);
void destroy_object(object * ptr);

ds_node * create_ds_node(object * new_data, char * key);
void destroy_ds_node(ds_node * old_node);

#endif // object_H
