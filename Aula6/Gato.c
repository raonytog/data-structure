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
    print("%s - ", gato->nome);
    switch (gato->nivelAgressividade) {
        case BRAVO:
            printf("BRAVO\n");
            break;

        case MANSO:
            printf("MANSO\n");
            break;
    }
}

void atribuiNivelAgressividadeCachorro(Gato *gato, int nivelAgressividade) {
    gato->nivelAgressividade = nivelAgressividade;
}