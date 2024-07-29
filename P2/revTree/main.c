#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

int main () {
    Tree *arvore = InitTree();
    arvore = InsertOnTree(arvore, "raony");
    arvore = InsertOnTree(arvore, "abc");
    arvore = InsertOnTree(arvore, "barbara pereira");
    arvore = InsertOnTree(arvore, "diva");
    int hight = HightTree(arvore);
    int leafs = LeafsTree(arvore);
    printf("\nHight: %d, Leafs: %d\n\n", hight, leafs);
    PrintTree(arvore);
    printf("\n");

    arvore = RemoveFromTree(arvore, "raony");
    PrintTree(arvore);
    printf("\n");

    DestroyTree(arvore);
    return 0;
}