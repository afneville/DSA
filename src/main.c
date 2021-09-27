#include <stdio.h>
#include <stdlib.h>
#include "../includes/linked_list.h"
#include "../includes/map.h"
#include "../includes/tree.h"
#include "../includes/queue.h"
#include "../includes/stack.h"

int main(int argc, char *argv[]){

    // map data structure
    map * map1_p = create_map();

    insert_map(map1_p, 'a', 1);
    insert_map(map1_p, 'j', 2);
    insert_map(map1_p, 'b', 3);
    insert_map(map1_p, 'f', 1);
    insert_map(map1_p, 'd', 5);
    insert_map(map1_p, 'i', 2);
    insert_map(map1_p, 'c', 2);
    insert_map(map1_p, 'h', 3);
    insert_map(map1_p, 'e', 4);
    insert_map(map1_p, 'g', 8);

    printf("\n%c => %d\n", 'a', search_map(map1_p, 'a'));
    printf("%c => %d\n", 'e', search_map(map1_p, 'e'));

    // linked list data structure
    printf("\n");
    linked_list * list_p = create_linked_list();

    append_list(list_p, 3);
    append_list(list_p, 2);
    append_list(list_p, 1);

    traverse_list(list_p);
    destroy_list(list_p);

    // binary tree data structure
    printf("\n");
    tree_node * root_p = create_tree_node();

    insert_tree(root_p, 2);
    insert_tree(root_p, 4);
    insert_tree(root_p, 12);
    insert_tree(root_p, 3);
    insert_tree(root_p, 7);
    insert_tree(root_p, 12);
    insert_tree(root_p, 1);
    insert_tree(root_p, 19);

    traverse_tree(root_p);
    destroy_tree(root_p);

    // queue data structure
    printf("\n");
    queue * queue_p = new_queue(5);
    printf("%d\n", queue_isEmpty(queue_p)); // 1
    printf("%d\n", queue_isFull(queue_p));  // 0

    enQueue(queue_p, 1);
    printf("%d\n", queue_isEmpty(queue_p)); // 0
    printf("%d\n", queue_isFull(queue_p));  // 0
    printf("%d\n", deQueue(queue_p)); // 4

    printf("\n");
    enQueue(queue_p, 1);
    enQueue(queue_p, 2);
    enQueue(queue_p, 3);
    enQueue(queue_p, 4);
    enQueue(queue_p, 5);
    enQueue(queue_p, 6);
    printf("%d\n", deQueue(queue_p)); // 4
    printf("%d\n", deQueue(queue_p)); // 4
    printf("%d\n", deQueue(queue_p)); // 4
    printf("%d\n", deQueue(queue_p)); // 4
    printf("%d\n", deQueue(queue_p)); // 4
    printf("%d\n", deQueue(queue_p)); // 4
    printf("%d\n", deQueue(queue_p)); // 4

    printf("\n");
    stack * stack_p = new_stack(5);
    printf("%d\n", stack_isEmpty(stack_p));
    printf("%d\n", stack_isFull(stack_p));
    push(stack_p, 4);
    printf("%d\n", peek(stack_p));
    printf("%d\n", pop(stack_p));
    push(stack_p, 1);
    push(stack_p, 2);
    push(stack_p, 3);
    push(stack_p, 4);
    push(stack_p, 5);
    push(stack_p, 6);
    printf("%d\n", pop(stack_p));
    printf("%d\n", pop(stack_p));
    printf("%d\n", pop(stack_p));
    printf("%d\n", pop(stack_p));
    printf("%d\n", pop(stack_p));

    return 0;

}
