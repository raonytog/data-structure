#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula Celula;
struct Celula {
    Pessoa *pessoa;
    struct Celula *next;
};

struct hash {
    Celula **pessoa;
    int max, atual;
};

Hash *InitHash(int size) {
    if (size <= 0) return NULL;

    Hash *new = malloc(sizeof(Hash));
    new->pessoa = calloc(size, sizeof(Pessoa*));
    new->max = size;
    new->atual = 0;
    return new;
}

int HashFunction(char *key, int size) {
    if (!key || size <= 0) return -1;

    int total = 0;
    for (size_t i = 0; i < strlen(key)+1; i++)
        total += key[i];
    
    return total % size;
}

void HashSearch(Hash *hashtable, char *key, char value) {
    if (!hashtable || !key || !value) return;

    int idx = HashFunction(key, hashtable->max);

    int exit = 0;
    Celula *auxiliar = hashtable->pessoa[idx];
    while (auxiliar) {
        if (strcmp(getNomePessoa(auxiliar->pessoa), key) == 0) {
            switch (value) {
                case 'P':
                    IncrementaPresenca(auxiliar->pessoa);
                    exit = 1;
                    break;

                case 'F':
                    IncrementaFalta(auxiliar->pessoa);
                    exit = 1;
                    break;
            }
        }

        if (exit) break;
        else auxiliar = auxiliar->next;
    }
}

Hash *InsertHash(Hash *hashtable, Pessoa *pessoa) {
    if (!hashtable || !pessoa) return NULL;

    /** Acha o indice e percorre ate o final da lista no indice */
    int idx = HashFunction(getNomePessoa(pessoa), hashtable->max);
    Celula *auxiliar = hashtable->pessoa[idx];
    while (auxiliar) 
        auxiliar = auxiliar->next;

    if (auxiliar == NULL) {
        Celula *new = malloc(sizeof(Celula));
        new->next = hashtable->pessoa[idx];
        new->pessoa = pessoa;

        hashtable->pessoa[idx] = new;
        hashtable->atual++; 
    }

    return hashtable;
}

void PrintHash(Hash *hashtable) {
    if (!hashtable) return;

    for (size_t i = 0; i < hashtable->max; i++) {
        if (hashtable->pessoa[i]) {
            ImprimePessoa(hashtable->pessoa[i]->pessoa);
            Celula *auxiliar = hashtable->pessoa[i]->next;
            while (auxiliar != NULL) {
                ImprimePessoa(auxiliar->pessoa);
                auxiliar = auxiliar->next;
            }
        }
    }
}

void DestroyCelula(Celula *cell) {
    if (!cell) return;

    Celula *auxiliar = cell;
    while (auxiliar) {
        auxiliar = auxiliar->next;
        DestroiPessoa(cell->pessoa);
        free(cell);
        cell = auxiliar;
    }
}

void DestroyHash(Hash *hashtable) {
    if (!hashtable) return;

    for (int i = 0; i < hashtable->max; i++)
        DestroyCelula(hashtable->pessoa[i]);

    free(hashtable->pessoa);
    free(hashtable);
}
