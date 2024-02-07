#include <stdio.h>
#include <stdlib.h>
#include "../inc/linked_list.h"
#include "../inc/map.h"
#include "../inc/tree.h"
#include "../inc/queue.h"
#include "../inc/stack.h"

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

    return 0;
}
