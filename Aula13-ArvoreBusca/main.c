#include "arv.h"
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    Aluno *aline = CriaAluno("aline", 1);
    Aluno *barbara = CriaAluno("barbara", 2);
    Aluno *eduardo = CriaAluno("eduardo", 13);
    Aluno *gabriel = CriaAluno("gabriel", 12);
    Aluno *malu = CriaAluno("malu", 11);
    Aluno *marcela = CriaAluno("marcela", 9);
    Aluno *raony = CriaAluno("raony", 10);



    Arv *node = cria_arvore();
    node = insere_aluno_arvore(node, marcela);
    node = insere_aluno_arvore(node, raony);
    node = insere_aluno_arvore(node, eduardo);
    node = insere_aluno_arvore(node, barbara);
    node = insere_aluno_arvore(node, aline);

    imprime_arvore(node);
    node = busca_binaria(node, 1);
    printf("\n");

    node = retira_aluno_arvore(node, 1);
    imprime_arvore(node);


    return 0;
}