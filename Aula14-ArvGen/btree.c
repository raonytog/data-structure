#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree {
    void *data;
    struct Tree *left;
    struct Tree *right;

    func_compare_tree_node compare_tree_node;
    func_print print_tree;
    func_destroy destroy_tree;
};

Tree *CreateTree(void* data, Tree *left, Tree *right, 
                func_print imprime, func_destroy destroi, 
                func_compare_tree_node compara) {
    Tree *new = malloc(sizeof(Tree));
    new->left = left;
    new->right = right;
    new->data = data;
    new->destroy_tree = destroi;
    new->print_tree = imprime;
    new->compare_tree_node = compara;

    return new;
}

Tree *InsertOnTree(void *data, Tree *node, func_print imprime, 
                   func_destroy destroi, func_compare_tree_node compara) {
    if (node == NULL) {
        node = CreateTree(data, NULL, NULL, imprime, destroi, compara);
        return node;
    }

    if (node->compare_tree_node(node->data, data) <= 0) 
        node->right = InsertOnTree(node->right, data, node->print_tree,
                                   node->destroy_tree, node->compare_tree_node);

    else if (node->compare_tree_node(node->data, data) > 0)
        node->left = InsertOnTree(node->left, data, node->print_tree,
                                  node->destroy_tree, node->compare_tree_node);

    return node;
}

Tree *RemoveOnTree(void *data, Tree *node) {

}

Tree *BinarySearch(void *data, Tree *node) {
    if (!data) return;

    if (node->compare_tree_node(node->data, data) == 0)
        return node;

    else if (node->compare_tree_node(node->data, data) > 0)
        return BinarySearch(data, node->right);

    else return BinarySearch(data, node->left);
}

void PrintTree(Tree *node) {
    printf("<");
    if (node) {
        node->print_tree(node);
        node->print_tree(node->right);
        node->print_tree(node->left);
    }
    printf(">");
}

void LiberaTree(Tree *node) {
    if (!node) return;

    LiberaTree(node->left);
    LiberaTree(node->right);

    free(node);
}