#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_T {

  int value;
  struct tree_node_T * left;
  struct tree_node_T * right;

} tree_node;

tree_node * create_node() {

  tree_node * new_node = (tree_node *) malloc(sizeof(tree_node));
  new_node->value = NULL;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;

}

void insert(tree_node * node_p, int value) {

    if (node_p->value) {

        if (value <= node_p->value) {

            if (! node_p->left) { node_p->left = create_node(); }
            insert(node_p->left, value);

        } else if (value > node_p->value) {

          if (! node_p->right) { node_p->right = create_node(); }
          insert(node_p->right, value);

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

int main(){

  tree_node * root_p = create_node();

  insert(root_p, 2);
  insert(root_p, 4);
  insert(root_p, 12);
  insert(root_p, 3);
  insert(root_p, 7);
  insert(root_p, 12);
  insert(root_p, 1);
  insert(root_p, 19);

  traverse_tree(root_p);
  destroy_tree(root_p);

  return 0;

}
