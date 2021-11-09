#ifndef object_H
    
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


object * new_object(object_type type, void * ptr);
void destroy_object(object * prt);

#endif // object_H
