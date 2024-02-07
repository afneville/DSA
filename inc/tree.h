#ifndef tree_H
#define tree_H

typedef struct tree_node_T {

  int value;
  struct tree_node_T * left;
  struct tree_node_T * right;

} tree_node;

tree_node * create_tree_node();
void insert_tree(tree_node * node_p, int value);
void traverse_tree(tree_node * node_p);
void destroy_tree(tree_node * node_p);

#endif // !tree_H
