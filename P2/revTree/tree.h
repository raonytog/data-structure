#ifndef _TREE_H_
#define _TREE_H_

typedef struct Tree Tree;

Tree *InitTree();

Tree *InsertOnTree(Tree *treeNode, char *word);

Tree *RemoveFromTree(Tree *treeNode, char *word);

Tree *SearchOnTree(Tree *treeNode, char *word);

void DestroyTree(Tree *treeNode);

void PrintTree(Tree *treeNode);

int LeafsTree(Tree *treeNode);

int HightTree(Tree *treeNode);

#endif //  _TREE_H_