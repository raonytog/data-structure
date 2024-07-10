#include "palavra.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Palavra {
    char *palavra;
    int n;
    struct Palavra *next;
};

Palavra *InicPalavra(char *pal) {
    Palavra *new = malloc(sizeof(Palavra));
    new->palavra = strdup(pal);
    new->n = 1;
    new->next = NULL;
    return new;
}

char *RetornaPalavra(Palavra *pal) {
    if (!pal) return '\0';
    return pal->palavra;
}

int RetornaOcorrencias(Palavra *pal) {
    if (!pal) return -1;
    return pal->n;
}

void IncrementaOcorrencia(Palavra *pal) {
    if (!pal) return;
    pal->n++;
}

Palavra *LiberaPalavra(Palavra *pal) {
    if (pal) {
        free(pal->palavra);
        if (pal->next != NULL) return LiberaPalavra(pal->next);
        free(pal);
    }
    return NULL;
}



