#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

typedef struct Node Node;

Node *create_node(int value);

void insert_node_tree(Node *a, Node *sa);

int search(Node *node, int value);

void print_tree(Node *node);

void destroy_tree(Node *node);

#endif // !_BINARYTREE_H_