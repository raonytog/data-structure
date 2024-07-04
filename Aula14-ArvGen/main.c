#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"
// #include "aluno.h"
#include "loja.h"

// int main () {
//     Aluno *malu = CriaAluno("malu", 9);
//     Aluno *raony = CriaAluno("raony", 10);
//     Aluno *marcela = CriaAluno("marcela", 11);
//     Aluno *barbara = CriaAluno("barbara", 20);

//     Tree *treeNode = NULL;
//     treeNode = InsertOnTree(raony, treeNode, ImprimeAluno, LiberaAluno, ComparaID);
//     treeNode = InsertOnTree(malu, treeNode, ImprimeAluno, LiberaAluno, ComparaID);
//     treeNode = InsertOnTree(marcela, treeNode, ImprimeAluno, LiberaAluno, ComparaID);
//     treeNode = InsertOnTree(barbara, treeNode, ImprimeAluno, LiberaAluno, ComparaID);

//     PrintTree(treeNode);
//     printf("\n");

//     Tree *encontrado = BinarySearch(barbara, treeNode);
//     if (encontrado) {
//         PrintTree(encontrado);
//         printf("\n");
//     }

//     LiberaTree(treeNode);

//     LiberaAluno(raony);
//     LiberaAluno(barbara);
//     LiberaAluno(malu);
//     LiberaAluno(marcela);

//     return 0;
// }

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

    return 0;
}