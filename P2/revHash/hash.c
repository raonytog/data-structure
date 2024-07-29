#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

typedef struct Cell {
    char *palavra;
    int ocorrencia;

    struct Cell *next;
} Cell;

struct Hash {
    Cell **data;
    int max, real;
};

Hash *InitHash(int size) {
    if (size <= 0) return NULL;

    Hash *new = malloc(sizeof(Hash));
    new->data = calloc(size, sizeof(Cell));
    new->max = size;
    new->real = 0;

    return new;
}

static int hash_func(char *key, int size) {
    if (!key || size <= 0) return 0;

    int total=0;
    for(int i=0; i<strlen(key);i++)
        total += key[i];

    return total%size;
}

void HashInsert(Hash *ht, char *palavra) {
    if (!ht || !palavra) return;

    int idx = hash_func(palavra, ht->max);

    Cell *auxiliar = ht->data[idx];
    while (auxiliar) {
        if (strcmp(auxiliar->palavra, palavra) == 0) {
            auxiliar->ocorrencia++;
            return;
        }
        auxiliar = auxiliar->next;
    }

    Cell *new = malloc(sizeof(Cell));
    new->palavra = strdup(palavra);
    new->ocorrencia = 1;

    new->next = ht->data[idx];
    ht->data[idx] = new;
    ht->real++;
}

int HashSearch(Hash *ht, char *palavra) {
    if (!ht || !palavra) return -1;

    int idx = hash_func(palavra, ht->max);

    Cell *auxiliar = ht->data[idx];
    while (auxiliar) {
        if (strcmp(auxiliar->palavra, palavra) == 0)
            return auxiliar->ocorrencia;

        auxiliar = auxiliar->next;
    }

    return -1;
}

static void PrintCell(Cell *c) {
    if (!c) return;

    printf("%s - %d\n", c->palavra, c->ocorrencia);
    PrintCell(c->next);
}

void PrintHash(Hash *ht) {
    if (!ht) return;

    for (int i = 0; i < ht->max; i++) {
        PrintCell(ht->data[i]);
    }
}

static void DestroyCell(Cell *c) {
    if (!c) return;

    free(c->palavra);
    free(c);
}

void DestroyHash(Hash *ht) {
    if (!ht) return;

    for (int i = 0; i < ht->max; i++) {
        DestroyCell(ht->data[i]);
    }
    free(ht->data);
    free(ht);
}