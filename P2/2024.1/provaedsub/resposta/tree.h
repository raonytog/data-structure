/** Raony Togneri Gomes */

#ifndef _TREE_H_
#define _TREE_H_

typedef struct Tree Tree;

Tree *InitTree();

Tree *InsertTree(Tree *treeNode, char *palavra);

Tree *BinarySearch(Tree *treeNode, char *palavra);

void incFrequencia(Tree *treeNode);

Tree *LiberaTree(Tree *treeNode);

Tree *PrintTree(Tree *treeNode);

int qtdPalavrasDistintas(Tree *treeNode);

int qtdPalavrastotais(Tree *treeNode);

void PreencheVetor(Tree *arvore, Tree **vetor, int *atual);

void PrintVetor(Tree *arvore, Tree **vetor, int size);

int ComparaFrequencia(const void *a, const void *b);

int ComparaAlfabetica(const void *a, const void *b);

Tree *findMaiorFreq(Tree *arvore);

#endif