#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tadhash.h"

/**
 * Raony Togneri Gomes
*/

typedef struct Cell Cell;

struct Cell {
    Pais *pais;
    Cell *next;
};

struct Hash {
    Cell **data;
    int max, atual;
};

Hash *InitHash() {
    Hash *new = malloc(sizeof(Hash));
    new->data = calloc(HASH_MAX, sizeof(Cell));
    new->max = HASH_MAX;
    new->atual = 0;
}

static int hash_func(char *key, int size) {
    if (!key || size <= 0) return 0;

    int total = 0;
    for (int i = 0; i < strlen(key); i++)
        total += key[i];

    return total%size;
}

void InsertHash(Hash *ht, Pais *pais) {
    if (!ht || !pais) return;

    int idx = hash_func(getPaisName(pais), HASH_MAX);

    Cell *auxiliar = ht->data[idx];
    while (auxiliar) auxiliar = auxiliar->next;

    Cell *new = malloc(sizeof(Cell));
    new->pais = pais;
    new->next = ht->data[idx];

    ht->data[idx] = new;
    ht->atual++;
}

Pais *SearchHash(Hash *ht, char *nome) {
    if (!ht || !nome) return NULL;

    int idx = hash_func(nome, HASH_MAX);

    Cell *auxiliar = ht->data[idx];
    while (auxiliar) {
        if (strcmp(getPaisName(auxiliar->pais), nome) == 0) return auxiliar->pais;
        auxiliar = auxiliar->next;
    }

    return NULL;
}

static void PrintCell(Cell *c) {
    if (!c) return;
    PrintPais(c->pais);
    PrintCell(c->next);
}

void PrintHash(Hash *ht) {
    if (!ht) return;

    for (int i = 0; i < HASH_MAX; i++) {
        PrintCell(ht->data[i]);
    }
}

static void DestroyCell(Cell *c) {
    if (!c) return;

    DestroyPais(c->pais);
    DestroyCell(c->next);
    free(c);

    c = NULL;
}

void DestroyHash(Hash *ht) {
    if (!ht) return;

    for (int i = 0; i < HASH_MAX; i++) {
        DestroyCell(ht->data[i]);
    }
    free(ht->data);
    free(ht);

    ht = NULL;
}

int getHashSize(Hash *ht) {
    if (!ht) return 0;
    return ht->atual;
}

void FillVector(Hash *ht, Pais **vector) {
    if (!ht || !vector) return;

    int idx = 0, i = 0;
    while (idx < 17) {

        Cell *auxiliar = ht->data[idx];
        while (auxiliar) {
            vector[i] = auxiliar->pais;
            i++; auxiliar = auxiliar->next;
        }
        idx++;
    }
}

