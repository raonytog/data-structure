#include "binaryTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    Node *filho, *irmao;
};

Node *create_node(int value) {
    Node *new = malloc(sizeof(Node));
    if (new) {
        new->data = value;
        new->filho = new->irmao = NULL;
    }
    return new;
}

/**
 * Insere a sub-arvore na arvore, pelo comeco
 */
void insert_node_tree(Node *a, Node *sa) {
    sa->irmao = a->filho;
    a->filho = sa;
}

int search(Node *node, int value);

void print_tree(Node *node) {
    printf("<%d", node->data);
    for (Node *i = node->irmao; i != NULL; i = i->filho)
        print_tree(node);
    printf(">");
}

void destroy_tree(Node *node);