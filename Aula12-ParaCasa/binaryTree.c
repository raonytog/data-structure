#include "binaryTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    Node *child1, *child2, *child3;
};

Node *create_node(int num) {
    Node *n = malloc(sizeof(Node));
    if (n) {
        n->child1 = n->child2 = n->child3 = NULL;
        n->data = num;
    }

    return n;
}

void insert_node_tree(Node *a, Node *sa) {

}

void search(Node *node, int value);

void print_tree(Node *node) {
    if (node) {
        printf("<%c", node->data);
        print_tree(node->child1);
        print_tree(node->child2);
        print_tree(node->child3);
        printf(">");
    }
}

void destroy_tree(Node *node);