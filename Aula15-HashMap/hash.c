#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "palavra.h"

struct cell{
    Palavra *word;
    Cell *next;
};

struct hash {
    Cell **table;
    int max_size, actual_size;
};

Hash *initHash(int size) {
    if (size <= 0) return NULL;

    Hash *new = malloc(sizeof(Hash));
    new->max_size = size;
    new->actual_size = 0;
    new->table = calloc(new->max_size, sizeof(Cell*));

    return new;
}

int hashFunction(char *palavra, int size) {
    if (!palavra || size <= 0) return -1;

    int total = 0;
    for (int i = 0; i < strlen(palavra); i++) {
        total += palavra[i];
    }

    return total % size;
}

void insertHash(Hash *hashTable, char *palavra) {
    if (!palavra || !hashTable) return;

    int idx = hashFunction(palavra, hashTable->max_size);
    Cell *auxiliar = hashTable->table[idx];

    /** 
     * percorre ate o ultimo no da lista de palavras com mesmo somatorio ascii
     */
    while (auxiliar) {
        if (strcmp(palavra, retornaPalavra(auxiliar->word)) == 0) {
            incrementaFrequencia(auxiliar->word);
            break;
        }
        else auxiliar = auxiliar->next;
    }

    /** 
     * se nao achar a palavra la, quer dizer que nao existe
     * portanto, cria-se e insere a mesma na lista de palavras
     * com mesmo indice na hash
     */
    if (auxiliar == NULL) {
        Cell *new = malloc(sizeof(Cell));
        new->word = criaPalavra(palavra);
        new->next = hashTable->table[idx];

        hashTable->table[idx] = new;
        hashTable->actual_size++;
    }
}

void printHash(Hash *hashTable) {
    if (!hashTable) return;

    for (int i = 0; i < hashTable->max_size; i++) {
        if (hashTable->table[i] != NULL) { 
            ImprimeCelula(hashTable->table[i]);
            printf("\n");
        }
    }
}

void destroyHash(Hash *hashTable) {
    if (!hashTable) return;

    for (int i = 0; i < hashTable->max_size; i++)
        LiberaCelula(hashTable->table[i]);

    free(hashTable->table);
    free(hashTable);
}

void LiberaCelula(Cell *celula) {
    if (!celula) return;

    Cell *auxiliar = celula->next;
    while (celula) {
        liberaPalavra(celula->word);
        free(celula);
        celula = auxiliar;
        auxiliar = auxiliar->next;
    }
}

void ImprimeCelula(Cell *celula) {
    if (!celula) return;

    printf("(%s, %d) ", retornaPalavra(celula->word), retornaFrequencia(celula->word));
    ImprimeCelula(celula->next);
}