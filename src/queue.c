#include "../includes/queue.h"
#include <stdlib.h>

queue * new_queue(int size) {

    queue * queue_p = (queue *) malloc(sizeof(queue));
    queue_p->entries = (int *) malloc(sizeof(int) * size);
    queue_p->max_entries = size;
    for (int i = 0; i < size; i ++)
        queue_p->entries[i] = 0;
    queue_p->start = 0; 
    queue_p->end = 0;

    return queue_p;

};

int enQueue(queue * queue_p, int value){
    if (queue_isFull(queue_p) == 1) {
        return -1;
    } else {
        queue_p->entries[queue_p->end] = value;
        queue_p->end = (queue_p->end + 1) % queue_p->max_entries;
        return 0;
    }
};

int deQueue(queue * queue_p) {
    if (queue_isEmpty(queue_p) == 1) {
        return -1;
    } else {
        int value = queue_p->entries[queue_p->start];
        queue_p->entries[queue_p->start] = 0;
        queue_p->start = (queue_p->start + 1) % queue_p->max_entries;
        return value;
    }
};

int queue_isEmpty(queue * queue_p){
    if (queue_p->entries[queue_p->start] == 0) {
        return 1;
    } else {
        return 0;
    }
};

int queue_isFull(queue * queue_p) {
    if (queue_p->end == queue_p->start && queue_p->entries[queue_p->start] != 0) {
        return 1;
    } else {
        return 0;
    }
};

void destroy_queue(queue * queue_p) {

    free(queue_p->entries);
    free(queue_p);
}
