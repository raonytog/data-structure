

#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Arv {
    Aluno *aluno;
    Arv *left, *right;
};

Arv *CriaArvore(Aluno *aluno, Arv *left, Arv *right) {
    Arv *a = malloc(sizeof(Arv));
    a->aluno = aluno;
    a->left = left;
    a->right = right;
    return a;
}

void LiberaArvore(Arv *a) {
    if (!a) return;

    LiberaArvore(a->left);
    LiberaArvore(a->right);

    free(a);
}

int EhArvoreVazia(Arv *a) {
    return a == NULL;
}

int AlunoPercenteArvore(Arv *a, Aluno *aluno) {
    if (EhArvoreVazia(a) || !aluno) return 0;

    if (strcmp(RetornaNome(aluno), RetornaNome(a->aluno)) == 0) return 1;
    else {
        AlunoPercenteArvore(a->left, aluno);
        AlunoPercenteArvore(a->right, aluno);
    }
    
    return 0;
}

void ImprimeArvore(Arv *a) {
    printf("<");
    if(a) {
        ImprimeAluno(a->aluno);
        ImprimeArvore(a->left);
        ImprimeArvore(a->right);
    }
    printf("> ");
}


int folhas(Arv *a) {
    if (!a) return 0;

    if (EhArvoreVazia(a->left) && EhArvoreVazia(a->right)) return 1;
    else if (!EhArvoreVazia(a->left) && EhArvoreVazia(a->right)) return folhas(a->right);
    else if (EhArvoreVazia(a->left) && !EhArvoreVazia(a->right)) return folhas(a->left);

    return folhas(a->left) + folhas(a->right);
}

int ocorrencias(Arv *a, Aluno *aluno) {
    if (EhArvoreVazia(a)) return 0;

    if (strcmp(RetornaNome(aluno), RetornaNome(a->aluno)) == 0) 
        return 1 + ocorrencias(a->left, aluno) + ocorrencias(a->right, aluno);

    return ocorrencias(a->left, aluno) + ocorrencias(a->right, aluno);
}

static int max(int a, int b) {
    return a > b ? a : b;
}

int altura(Arv *a) {
    if (EhArvoreVazia(a)) return -1;
    else return 1 + max(altura(a->left), altura(a->right));
}