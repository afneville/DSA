#include <stdio.h>
#include <stdlib.h>
#include "../includes/tree.h"

tree_node * create_tree_node() {

  tree_node * new_node = (tree_node *) malloc(sizeof(tree_node));
  new_node->value = NULL;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;

}

void insert_tree(tree_node * node_p, int value) {

    if (node_p->value) {

        if (value <= node_p->value) {

            if (! node_p->left) { node_p->left = create_tree_node(); }
            insert_tree(node_p->left, value);

        } else if (value > node_p->value) {

          if (! node_p->right) { node_p->right = create_tree_node(); }
          insert_tree(node_p->right, value);

        }

    } else { node_p->value = value; }

}

void traverse_tree(tree_node * node_p) {

    if (node_p->left){ traverse_tree(node_p->left); }
    printf("%d\n", node_p->value);
    if (node_p->right){ traverse_tree(node_p->right); }

}

void destroy_tree(tree_node * node_p) {

    if (node_p->left){ destroy_tree(node_p->left); }
    if (node_p->right){ destroy_tree(node_p->right); }
    free(node_p);

}
