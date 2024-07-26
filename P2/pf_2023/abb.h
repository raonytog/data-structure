#ifndef _ABB_H_
#define _ABB_H_

#include <stdio.h>

typedef struct Tree Tree;

Tree *InitTree();

Tree *InsertTree(Tree *node, char *name);

Tree *RemoveTree(Tree *node, char *name);

Tree *BinarySearch(Tree *node, char *name, char valid);

void PrintTree(Tree *node);
void PrintTreeFile(Tree *node, FILE *file);

void DestroyTree(Tree *node);

#endif