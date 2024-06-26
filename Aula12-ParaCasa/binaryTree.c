#include "binaryTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Tem algo de errado ainda, parece tudo uma lista encadeada e nao uma arvore binaria
 */

struct Node {
    int data;
    Node *first, *next;
};

Node *create_node(int num) {
    Node *n = malloc(sizeof(Node));
    if (n) {
        n->next = n->first = NULL;
        n->data = num;
    }

    return n;
}

void insert_node_tree(Node *a, Node *sa) {
    if (!a || !sa) return;
    sa->next = a->first;
    a->first = sa;
}

int search(Node *node, int value) {
    for (Node *i = node; i != NULL; i = i->next) {
        if (i->data == value) return 1;
    }

    return 0;
}

void print_tree(Node *node) {
    if (!node) return;

    printf("<%d ", node->data);
    for (Node *i = node->first; i != NULL; i = i->next) {
        print_tree(i);
        printf(">");
    }

}

void destroy_tree(Node *node) {
    if (!node) return;

    Node *auxiliar = node->first;
    while (auxiliar) {
        auxiliar = node->next;
        free(node->first);
        node->first = auxiliar;
    }

    free(node);
}