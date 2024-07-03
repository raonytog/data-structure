#ifndef _BTREE_H_
#define _BTREE_H_

typedef struct Tree Tree;

typedef int (*func_compare_tree_node)(void *data1, void *data2);
typedef void (*func_print)(void *data);
typedef void (*func_destroy)(void *data);

Tree *CreateTree(void* data, Tree *left, Tree *right, 
                func_print imprime, func_destroy destroi, 
                func_compare_tree_node compara);

Tree *InsertOnTree(void *data, Tree *node, func_print imprime, 
                   func_destroy destroi, func_compare_tree_node compara);

Tree *RemoveOnTree(void *data, Tree *node);

Tree *BinarySearch(void *data, Tree *node);

void PrintTree(Tree *node);

void LiberaTree(Tree *node);

#endif
