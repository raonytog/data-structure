#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palavra.h"

struct palavra {
    char *palavra;
    int frequencia;
};

Palavra *criaPalavra(char *string) {
    if (!string) return NULL;

    Palavra *new = malloc(sizeof(Palavra));
    new->palavra = strdup(string);
    new->frequencia = 1;
    return new;
}

char *retornaPalavra(Palavra *palavra) {
    if (!palavra) return '\0';
    return palavra->palavra;
}

int retornaFrequencia(Palavra *palavra) {
    if (!palavra) return -1;
    return palavra->frequencia;
}

void incrementaFrequencia(Palavra *palavra) {
    if (!palavra) return;
    palavra->frequencia++;
}

void imprimePalavra(Palavra *palavra) {
    if (!palavra) return;
    printf("%s", palavra->palavra);
}

void liberaPalavra(Palavra *palavra) {
    if (!palavra) return;
    free(palavra->palavra);
    free(palavra);
}