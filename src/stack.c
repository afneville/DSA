#include "../inc/stack.h"
#include <stdlib.h>

stack * new_stack(int size) {

    stack * stack_p = (stack *) malloc(sizeof(stack));
    stack_p->entries = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i ++)
        stack_p->entries[i] = 0;
    stack_p->max_entries = size;
    stack_p->top = -1;

    return stack_p;

};


int push(stack * stack_p, int value) {
    if (stack_isFull(stack_p) == 1) {
        return -1;
    } else {
        stack_p->top++;
        stack_p->entries[stack_p->top] = value;
        return 0;
    }
}
int pop(stack * stack_p) {
    if (stack_isEmpty(stack_p) == 1) {
        return -1;
    } else {

        int value = stack_p->entries[stack_p->top];
        stack_p->entries[stack_p->top] = 0;
        if (stack_p->top >= 0)
            stack_p->top--;

        return value;
    }
}

int peek(stack * stack_p) {
    if (stack_isEmpty(stack_p) == 1) {
        return -1;
    } else {
        return stack_p->entries[stack_p->top];
    }
}

int stack_isEmpty(stack * stack_p) {
    if (stack_p->entries[0] == 0) {
        return 1;
    } else {
        return 0;
    }
}
int stack_isFull(stack * stack_p) {
    if (stack_p->top == stack_p->max_entries - 1) {
        return 1;
    } else {
        return 0;
    }
};

void destroy_stack(stack * stack_p) {
    free(stack_p->entries);
    free(stack_p);
}
