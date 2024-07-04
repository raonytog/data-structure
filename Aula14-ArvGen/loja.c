#include "loja.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Loja {
    char *nome;
    int id, qtdProdutos;
};

Loja *CriaLoja(char *nome, int id, int qtdProdutos) {
    Loja *a = malloc(sizeof(Loja));
    if (!a) return NULL;

    a->nome = strdup(nome);
    a->id = id;
    a->qtdProdutos = qtdProdutos;
    
    return a;
}

void ImprimeLoja(void *loja) {
    if (!loja) return;

    Loja *new = (Loja*) loja;
    printf("%s ", new->nome);
}

void LiberaLoja(void *loja) {
    if (!loja) return;

    Loja *new = (Loja*) loja;
    free(new->nome);
    free(new);
}

char *RetornaNome(void *loja) {
    if (!loja) return '\0';
    
    Loja *new = (Loja*) loja;
    return new->nome;
}

int RetornaId(void *loja) {
    if (!loja) return -1;

    Loja *new = (Loja*) loja;
    return new->id;
}

int ComparaID(void *a1, void *a2) {
    Loja *new1 = (Loja*) a1;
    Loja *new2 = (Loja*) a2;

    return new2->id - new1->id;
}