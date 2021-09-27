#ifndef stack_H
#define stack_H

typedef struct stack_T {
    int * entries;
    int max_entries;
    int top;
} stack;

stack * new_stack(int size);


int push(stack * stack_p, int value);
int pop(stack * stack_p);
int peek(stack * stack_p);

int stack_isEmpty(stack * stack_p);
int stack_isFull(stack * stack_p);

#endif
