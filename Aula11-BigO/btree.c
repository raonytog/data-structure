#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree {
    int *value;
    Tree *right, *left;
};

Tree *createTree(Tree *left, Tree *right) {
    Tree *t = malloc(sizeof(Tree));
    if (t) {
        t->left = left; t->right = right;
        return t;
    }

    return NULL;
}

void printTree(Tree *node) {
    printf("<");
    if (node) {
        printf("%d", node->value);
        printTree(node->left);
        printTree(node->right);
    }
    printf(">");

}

void destroyTree(Tree *node) {
    if (!node) return;

    destroyTree(node->right);
    destroyTree(node->left);
    free(node);
}