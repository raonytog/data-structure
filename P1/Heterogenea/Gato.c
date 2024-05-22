#include "Gato.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Gato {
    char *nome;
    int nivelAgressividade;
};

Gato *inicGato(char *nome, int nivelAgressividade) {
    Gato *g = malloc(sizeof(Gato));
    g->nome = strdup(nome);
    g->nivelAgressividade = nivelAgressividade;
    return g;
}


void liberaGato(Gato *gato) {
    free(gato->nome);
    free(gato);
}

void imprimeGato (Gato *gato) {
    printf("\tGato: %s\n", gato->nome);
}

void atribuiNivelAgressividadeGato(Gato *gato, int nivelAgressividade) {
    gato->nivelAgressividade = nivelAgressividade;
}

int getNivelAgressividadeGato(Gato *gato) {
    return gato->nivelAgressividade;
}