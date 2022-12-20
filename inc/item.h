#ifndef item_H
#define item_H
#include <stdbool.h>
#define DEFAULTREPRSIZE 6
    
// type aliases
typedef union item_type_U_ item_val;
typedef enum item_type_E_ item_type;
typedef struct item_type_T_ * item;

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

struct item_type_T_ {
    item_val val;
    item_type type;
    char * repr;
    int repr_len;
    unsigned long hash;
};

// allocation / deallocation
item item_new(item_type type, ...);
void item_del(item self);

// public functions
void item_modify(item self, item_type type, ...);
bool item_compare(item self, item other);
void item_print(item self);
char * item_repr(item self);
unsigned long item_hash(item self);

#endif // item_H
