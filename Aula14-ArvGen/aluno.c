
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char *nome;
    int id;
};

Aluno *CriaAluno(char *nome, int id) {
    Aluno *a = malloc(sizeof(Aluno));
    if (!a) return NULL;

    a->nome = strdup(nome);
    a->id = id;
    
    return a;
}

void ImprimeAluno(void *aluno) {
    if (!aluno) return;

    Aluno *new = (Aluno*) new;
    printf("%s ", new->nome);
}

void LiberaAluno(void *aluno) {
    if (!aluno) return;

    Aluno *new = (Aluno*) new;
    free(new->nome);
    free(new);
}

char *RetornaNome(void *aluno) {
    if (!aluno) return '\0';
    
    Aluno *new = (Aluno*) new;
    return new->nome;
}

int RetornaId(void *aluno) {
    if (!aluno) return -1;

    Aluno *new = (Aluno*) new;
    return new->id;
}

int ComparaID(void *a1, void *a2) {
    Aluno *new1 = (Aluno) a1;
    int new2 = (int) a2;

    return new2 - new1;
}