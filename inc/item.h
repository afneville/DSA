#ifndef item_H
#define item_H
    
typedef union item_type_U_ {
    int    int_val;
    float  flt_val;
    double dbl_val;
    char   char_val;
    char * str_val;
    void * ptr_val;
} item_val;

typedef enum item_type_E_ {
    Integer,
    Double,
    Float,
    Character,
    String,
    Pointer
} item_type;

typedef struct item_T {
    item_val val;
    item_type type;
} item;

item * new_item_p(item_type type, ...);
item init_item(item_type type, ...);
void print_item(item * ptr);
void del_item_p(item * ptr);

#endif // item_H
