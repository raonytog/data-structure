#include "abb.h"

#include <stdlib.h>
#include <string.h>

struct Tree {
    char *name;
    int presencas, faltas;
    Tree *left, *right;
};

Tree *InitTree() {
    return NULL;
}

Tree *InsertTree(Tree *node, char *name) {
    if (!node) {
        Tree *new = malloc(sizeof(Tree));
        new->faltas = new->presencas = 0;
        new->name = strdup(name);
        new->left = new->right = NULL;
        return new;
    }

    else if (strlen(name) > strlen(node->name)) 
        node->right = InsertTree(node->right, name);

    else 
        node->left = InsertTree(node->left, name);

    return node;
}

Tree *RemoveTree(Tree *node, char *name);

Tree *BinarySearch(Tree *node, char *name, char valid) {
    if (!node) return NULL;

    if (strcmp(node->name, name) == 0) {
        if (valid == 'P') node->presencas++;
        else node->faltas++;
        return node;
    }

    else if (strlen(name) > strlen(node->name)) 
        return BinarySearch(node->right, name, valid);

    else 
        return BinarySearch(node->left, name, valid);
}

void PrintTree(Tree *node) {
    if (!node) return;

    printf("%s %dP %dF\n", node->name, node->presencas, node->faltas);
    PrintTree(node->left);
    PrintTree(node->right);
}

void PrintTreeFile(Tree *node, FILE *file) {
    if (!node) return;

    fprintf(file ,"%s %dP %dF\n", node->name, node->presencas, node->faltas);
    PrintTreeFile(node->left, file);
    PrintTreeFile(node->right, file);
}

void DestroyTree(Tree *node) {
    if (!node) return;

    free(node->name);
    DestroyTree(node->left);
    DestroyTree(node->right);
    free(node);
}