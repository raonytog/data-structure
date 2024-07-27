#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char *nome;
    int matricula;
};

Aluno *InitAluno(char *nome, int matricula) {
    if (!nome || matricula < 0) return NULL;

    Aluno *new = malloc(sizeof(Aluno));
    new->matricula = matricula;
    new->nome = strdup(nome);

    return new;
}

char *GetAlunoNome(void *aluno) {
    if (!aluno) return '\0';
    Aluno *new = aluno;
    return new->nome;
}

int GetAlunoMatricula(void *aluno) {
    if (!aluno) return -1;
    Aluno *new = aluno;
    return new->matricula;
}

void PrintAluno(void *aluno) {
    if (!aluno) return;
    Aluno *new = aluno;
    printf("%s - %d\n", new->nome, new->matricula);
}

void LiberaAluno(void *aluno) {
    if (!aluno) return;
    Aluno *new = aluno;
    free(new->nome);
    free(new);
}

int ComparaMatriculaAlunos(void *a1, void *a2) {
    if (!a1 || !a2) return -10;
    Aluno *n1 = a1; int n2 = a2;
    return n1->matricula - n2;
}

int ComparaNomeAlunos(void *a1, void *a2) {
    if (!a1 || !a2) return -10;
    Aluno *n1 = a1; char *n2 = a2;
    return strlen(n1->nome) - strlen(n2);
}