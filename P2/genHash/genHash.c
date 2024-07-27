#include "genHash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cell Cell;

struct Cell {
    void *data;
    Cell *next;
};

struct Hash {
    Cell **data;
    int max, real;
};

Hash *InitHash(int max_size) {
    if (max_size<=0) return NULL;

    Hash *new = malloc(sizeof(Hash));
    new->data = calloc(max_size, sizeof(Cell));
    new->max = max_size;
    new->real = 0;
    return new;
}

void *HashSearch(Hash *hashtable, void *key, hfunction hash_func, compare compare_func) {
    if (!hashtable || !key) return NULL;

    int idx = hash_func(key, hashtable->max);

    Cell *auxiliar = hashtable->data[idx];
    while (auxiliar) {
        if (compare_func(auxiliar->data, key) == 0) return auxiliar->data;
        auxiliar = auxiliar->next;
    }
}

void HashInsert(Hash *hashtable, void *key, void *object, hfunction hash_func) {
    if (!hashtable || !object) return;

    int idx = hash_func(key, hashtable->max);

    Cell *auxiliar = hashtable->data[idx];
    while (auxiliar)
        auxiliar = auxiliar->next;
    
    if (auxiliar == NULL) {
        Cell *new = malloc(sizeof(Cell));
        new->data = object;
        new->next = hashtable->data[idx];

        hashtable->data[idx] = new;
        hashtable->real++;
    }
}

void LiberaCelula(Cell *c) {
    if (!c) return;

    Cell *auxiliar = c;
    while (auxiliar) {
        auxiliar = auxiliar->next;
        free(c);
        c = auxiliar;
    }
}

void LiberaHash(Hash *hashtable) {
    if (!hashtable) return;

    for (int i = 0; i < hashtable->max; i++) {
        LiberaCelula(hashtable->data[i]);
    }
    free(hashtable->data);
    free(hashtable);
}

void imprimeCell(Cell *c, printhash print) {
    if (!c) return;

    Cell *auxiliar = c;
    while (auxiliar) {
        print(auxiliar->data);
        auxiliar = auxiliar->next;
    }
}

void ImprimeHash(Hash *hashtable, printhash print_func) {
    if (!hashtable) return;
    
    printf("Imprimindo a tabela hash:\n");
    for (int i = 0; i < hashtable->max; i++) {
        imprimeCell(hashtable->data[i], print_func);
    }
    printf("\n");
}