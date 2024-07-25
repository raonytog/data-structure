#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"
#include "loja.h"

int main () {
    Loja *padaria = CriaLoja("padaria", 8, 200);
    Loja *farmacia = CriaLoja("farmacia", 34, 380);
    Loja *supermercado = CriaLoja("super mercado", 12, 3420);
    Loja *bar = CriaLoja("bar", 7, 230);

    Tree *treeNode = NULL;
    treeNode = InsertOnTree(supermercado, treeNode, ImprimeLoja, LiberaLoja, ComparaID);
    treeNode = InsertOnTree(padaria, treeNode, ImprimeLoja, LiberaLoja, ComparaID);
    treeNode = InsertOnTree(farmacia, treeNode, ImprimeLoja, LiberaLoja, ComparaID);
    treeNode = InsertOnTree(bar, treeNode, ImprimeLoja, LiberaLoja, ComparaID);

    PrintTree(treeNode);
    printf("\n");

    Tree *find = BinarySearch(padaria, treeNode);
    PrintTree(find);
    printf("\n");

    RemoveOnTree(supermercado, treeNode);
    PrintTree(treeNode);
    printf("\n");

    LiberaLoja(padaria);
    LiberaLoja(farmacia);
    LiberaLoja(supermercado);
    LiberaLoja(bar);

    return 0;
}