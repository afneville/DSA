#ifndef object_H
#define object_H
    
typedef union object_data_U {
    double decimal_data;
    int integer_data;
    char * string_data;
} obj_data;

typedef enum object_type_E {
    Integer,
    Decimal,
    String
} obj_type;

typedef struct object_T {
    obj_data data;
    obj_type type;
} object;

typedef struct node_T {
    object * record;
    char * key;
    unsigned long hash;
    struct node_T * next;
    struct node_T * prev;
    struct node_T * left;
    struct node_T * right;
} node;

object * new_obj(obj_type type, void * ptr);
void repr_obj(object * ptr);
void del_obj(object * ptr);

node * new_node();
void del_node(node * old_node);

#endif // object_H
