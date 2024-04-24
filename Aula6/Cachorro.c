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
    print("%s - ", cachorro->nome);
    switch (cachorro->nivelAgressividade) {
        case BRAVO:
            printf("BRAVO\n");
            break;

        case MANSO:
            printf("MANSO\n");
            break;
    }
}

void liberaCachorro(Cachorro *cachorro) {
    free(cachorro->nome);
    free(cachorro);
}
