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

Tree *InsertOnTree(void *data, Tree *node, void (*imprime)(void *),
                   void (*destroi)(void *), int (*compara)(void *, void *)) {
    /** Se nao existe, cria */
    if (node == NULL)
        return CreateTree(data, NULL, NULL, imprime, destroi, compara);

    /** Se existir, verificar o valor para insercao na esquerda ou direita */
    else if (compara(node->data, data) < 0)
        node->right = InsertOnTree(data, node->right, imprime, destroi, compara);

    else 
        node->left = InsertOnTree(data, node->left, imprime, destroi, compara);

    return node;
}

Tree *RemoveOnTree(void *data, Tree *node) {
    if (!node) return NULL;

    Tree *info = BinarySearch(data, node);

    /** Se nao tiver filhos */
    if (node->right == NULL && node->left == NULL) 
        free(node);

    /** Se so tiver um filho */
    else if (node->right == NULL) {
        Tree *auxiliar = node;
        node = node->left;
        free(auxiliar);
    }

    else if (node->left == NULL) {
        Tree *auxiliar = node;
        node = node->right;
        free(auxiliar);
    }

    /** Se tiver dois filhos */
    Tree *auxiliar = node->left;
    while (auxiliar->right != NULL)
        auxiliar = auxiliar->right;
    
    /**  */
    void *info = node->data;
    node->data = auxiliar->data;
    auxiliar->data = info;
    node->left = RemoveOnTree(data, node->left);
}

Tree *BinarySearch(void *data, Tree *node) {
    if (!data || !node) return NULL;

    if (node->compare_tree_node(node->data, data) == 0)
        return node;

    else if (node->compare_tree_node(node->data, data) < 0)
        return BinarySearch(data, node->right);
    
    return BinarySearch(data, node->left);
}

void PrintTree(Tree *node) {
    printf("<");
    if (node) {
        node->print_tree(node->data);
        PrintTree(node->right);
        PrintTree(node->left);
    }
    printf(">");
}

void LiberaTree(Tree *node) {
    if (!node) return;

    LiberaTree(node->left);
    LiberaTree(node->right);

    free(node);
}