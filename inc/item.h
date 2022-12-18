#ifndef item_H
#define item_H
#include <stdbool.h>
#define DEFAULTREPRSIZE 6
    
// type aliases
typedef union item_type_U_ item_val;
typedef enum item_type_E_ item_type;
typedef struct item_T item;

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

struct item_T {
    item_val val;
    item_type type;
    char * repr;
    int repr_len;
    unsigned long hash;
};

// allocation / deallocation
item * new_item(item_type type, ...);
void del_item(item * self);

// public functions
void modify_item(item * self, item_type type, ...);
bool compare_item(item * self, item * other);
void print_item(item * self);
char * repr_item(item * self);
unsigned long hash_item(item * self);

#endif // item_H
