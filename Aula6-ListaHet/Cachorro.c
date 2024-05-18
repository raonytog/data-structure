#include "Cachorro.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Cachorro {
    char *nome;
    int nivelAgressividade;
};

Cachorro *inicCachorro(char *nome, int nivelAgressividade) {
    Cachorro *c = malloc(sizeof(Cachorro));
    c->nome = strdup(nome);
    c->nivelAgressividade = nivelAgressividade;
    return c;
}

void atribuiNivelAgressividadeCachorro(Cachorro *cachorro, int nivelAgressividade) {
    cachorro->nivelAgressividade = nivelAgressividade;
}

void imprimeCachorro(Cachorro *cachorro) {
    printf("\tCachorro: %s\n", cachorro->nome);

}

void liberaCachorro(Cachorro *cachorro) {
    free(cachorro->nome);
    free(cachorro);
}

int getNivelAgressividadeCachorro(Cachorro *cachorro) {
    return cachorro->nivelAgressividade;
}
