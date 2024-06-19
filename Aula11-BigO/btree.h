#ifndef _BTREE_
#define _BTREE_

typedef struct Tree Tree;

Tree *createTree(Tree *left, Tree *right);

void printTree(Tree *node);

void destroyTree(Tree *node);

#endif