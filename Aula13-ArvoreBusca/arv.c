#include "arv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Arv {
    Aluno *aluno;
    Arv *left, *right;
};

Arv *cria_arvore() {
    return NULL;
}

Aluno *busca_arvore(Arv *a, int id) {
    if (a == NULL) return NULL;
    else if (RetornaId(a->aluno) > id) busca_arvore(a->right, id);
    else if (RetornaId(a->aluno) < id) busca_arvore(a->left, id);
    else return a->aluno;
}

Arv *insere_aluno_arvore(Arv *a, Aluno *aluno) {
    if (a == NULL) {
        a = malloc(sizeof(Arv));
        a->aluno = aluno;
        a->left = a->right = NULL;
    } 

    else if (RetornaId(a->aluno) > RetornaId(aluno)) 
        a->left = insere_aluno_arvore(a->left, aluno);

    else 
        a->right = insere_aluno_arvore(a->right, aluno);

    return a;
}


Arv *retira_aluno_arvore(Arv *a, int id) {
    if (a == NULL) return NULL;
    
}

void imprime_arvore(Arv *a) {
    printf("<");
    if (a) {
        ImprimeAluno(a->aluno);
        imprime_arvore(a->left);
        imprime_arvore(a->right);
    }
    printf(">");
}

int busca_binaria(Arv *a, int id) {
    if (!a) return -1;

    if (RetornaId(a->aluno) == id) return 1;
    else if (id < RetornaId(a->aluno))
        return busca_binaria(a->left, id);

    else if (id > RetornaId(a->aluno))
        return busca_binaria(a->right, id);

    else 
        return 1;
}