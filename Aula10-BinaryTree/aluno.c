
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char *nome;
};

Aluno *CriaAluno(char *nome) {
    Aluno *a = malloc(sizeof(Aluno));
    if (!a) return NULL;

    a->nome = strdup(nome);
    return a;
}

void ImprimeAluno(Aluno *aluno) {
    if (!aluno) return;
    printf("%s ", aluno->nome);
}

void LiberaAluno(Aluno *aluno) {
    if (!aluno) return;

    free(aluno->nome);
    free(aluno);
}

char *RetornaNome(Aluno *aluno) {
    if (!aluno) return '\0';
    return aluno->nome;
}