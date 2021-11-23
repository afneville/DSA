#ifndef qs_H
#define qs_H

#include "./object.h"

typedef struct queue_T {
    object ** array;
    int head, tail;
    int size;
} queue;

typedef struct stack_T {
    object ** array;
    int head, tail;
    int size;
} stack;

#endif // qs_H
