#ifndef item_H
#define item_H
#include <stdbool.h>
#define DEFAULTREPRSIZE 6
    
// type aliases
typedef union item_type_U_ item_val;
typedef enum item_type_E_ item_type;
typedef struct item_T_ item;
typedef struct item_T_ * item_p;

// type definitions
union item_type_U_ {
    int    int_val;
    float  flt_val;
    double dbl_val;
    char   char_val;
    char * str_val;
    void * ptr_val;
};

enum item_type_E_ {
    Integer,
    Double,
    Float,
    Character,
    String,
    Pointer
};

struct item_T_ {
    item_val val;
    item_type type;
    char * repr;
    int repr_len;
    unsigned long hash;
};

// allocation / deallocation
item item_init(item_type type, ...);
item_p item_new(item_type type, ...);
void item_del(item_p self);

// public functions
item_p item_clone(item_p self);
void item_modify(item_p self, item_type type, ...);
bool item_compare(item_p self, item_p other);
void item_print(item_p self);
char * item_repr(item_p self);
unsigned long item_hash(item_p self);

#endif // item_H
