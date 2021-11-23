#ifndef qs_H
#define qs_H

#include "./object.h"

typedef enum qs_type_E {
    Stack,
    Queue
} qs_type;

typedef struct qs_T {
    object ** array;
    int head, tail;
    int size;
    qs_type type;
} qs;

qs * new_qs(qs_type type);
void del_qs(qs * qs_p);

void push(qs * qs_p);
node * peek(qs * qs_p);
node * pop(qs * qs_p);

void enqueue(qs * qs_p);
node * dequeue(qs * qs_p);

#endif // qs_H
