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
    Aluno *patricia = CriaAluno("patricia", 15);



    Arv *node = NULL;
    node = insere_aluno_arvore(node, marcela);
    node = insere_aluno_arvore(node, raony);
    node = insere_aluno_arvore(node, eduardo);
    node = insere_aluno_arvore(node, barbara);
    node = insere_aluno_arvore(node, aline);
    node = insere_aluno_arvore(node, malu);
    node = insere_aluno_arvore(node, patricia);

    printf("Arvore com todos os alunos:\n");
    imprime_arvore(node);
    int result = busca_binaria(node, 1);
    printf("\nresultado: %d\n\n", result);

    printf("Arvore sem a eduardo:\n");
    node = retira_aluno_arvore(node, 13);
    imprime_arvore(node);
    printf("\n\n");

    LiberaAluno(raony);
    LiberaAluno(barbara);
    LiberaAluno(malu);
    LiberaAluno(marcela);
    LiberaAluno(gabriel);
    LiberaAluno(eduardo);
    LiberaAluno(patricia);

    libera_arvore(node);

    return 0;
}