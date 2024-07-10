#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hash {
    Palavra **palavras;
    int size;
};

Hash *InicializaHash(int size) {
    Hash *new = malloc(sizeof(Hash));
    new->palavras = malloc(size * sizeof(Palavra*));
    new->size = size;

    for (int i = 0; i < size; i++)
        new->palavras[i] = NULL;
}

void InsereHash(Hash *h, Palavra *p) {
    if (!h || !p) return;
    
    int idx = hash_table(RetornaPalavra(p), h->size);
    if (h->palavras[idx]) {
        // InserePalavra();
    }

}

static int hash_table(char *string, int size) {
    if (!string) return -1;

    int total = 0;
    for (int i = 0; i < strlen(string); i++)
        total += string[i];

    return total % size;
}

Palavra *BuscaPalavra(Hash *h, char *string) {

}

void LiberaHash(Hash *h) {
    if (!h) return;

    for (int i = 0; i < h->size; i++)
        if (h->palavras[i] != NULL) LiberaPalavra(h->palavras[i]);

    free(h->palavras);
    free(h);
}