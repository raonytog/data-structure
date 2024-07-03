#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"
#include "aluno.h"

int main () {
    Aluno *malu = CriaAluno("malu", 9);
    Aluno *raony = CriaAluno("raony", 10);
    Aluno *marcela = CriaAluno("marcela", 11);

    Tree *treeNode = NULL;
    treeNode = InsertOnTree(malu, treeNode, ImprimeAluno, LiberaAluno, ComparaID);
    treeNode = InsertOnTree(raony, treeNode, ImprimeAluno, LiberaAluno, ComparaID);
    treeNode = InsertOnTree(malu, treeNode, ImprimeAluno, LiberaAluno, ComparaID);
    
    PrintTree(treeNode);
    LiberaTree(treeNode);

    return 0;
}