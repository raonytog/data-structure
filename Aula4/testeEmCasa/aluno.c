#include "aluno.h"

struct Aluno {
    char * nome;
    int matricula;
    float CR;
};

Aluno * CriaAluno(char *nome, float CR, int matricula) {
    Aluno * a = malloc(sizeof(Aluno));
    if (!a) exit(1);

    a->nome = strdup(nome);
    a->CR = CR;
    a->matricula = matricula;

    return a;
}

void LiberaAluno(Aluno *aluno) {
    if (!aluno) return;
    if (aluno->nome) free(aluno->nome);
    free(aluno);
}

void ImprimeAluno(Aluno *aluno) {
    printf("\tAluno: %s, Matricula: %03d, CR:%.2f\n", aluno->nome, aluno->matricula, aluno->CR);
}

int ComparaMatricula (Aluno *a, int matricula) {
    return a->matricula == matricula;
}