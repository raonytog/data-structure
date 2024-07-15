#include "tabelaRot.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pacote {
    int nextHop;
    Pacote *next;
};

struct Hash {
    Pacote **pacotes;
    int max;
    int size;
};

Hash *CriaHash(int size) {
    if (size <= 0) return NULL;

    Hash *new = malloc(sizeof(Hash));
    new->max = size;
    new->size = 0;
    new->pacotes = calloc(size, sizeof(Hash*));

    return new;
}

int HashFunction(char *key, int size) {
    if (!key) return -1;

    int total = 0;
    for (int i = 0; i < strlen(key); i++)
        total += key[i];
    
    return total % size;
}

void HashSearch(Hash *h, char *palavra) {
    if (!h || !palavra) return;

    int idx = HashFunction(palavra, h->max);
    if (idx != -1) ImprimePacotes(h->pacotes[idx]);
    else printf("Erro!\n");
}

void InsereHash(Hash *h, char *key) {
    if (!h) return;

    int idx = HashFunction(key, h->max);

    Pacote *auxiliar = h->pacotes[idx];
    if (auxiliar) {
        auxiliar = auxiliar->next;
    } 

    if (auxiliar == NULL) {
        Pacote *new = InitPacote(rand()%100);
        new->next = h->pacotes[idx];
        h->pacotes[idx] = new;
        h->size++;
    }
}

void LiberaHash(Hash *h) {
    if (!h) return;

    for (int i = 0; i < h->max; i++) {
        LiberaPacote(h->pacotes[i]);
    }

    free(h);
}

void ImprimeHash(Hash *h) {
    if (!h) return;
    for (int i = 0; i < h->max; i++) {
        if (h->pacotes[i]) {
            printf("\nIndice: %d\n", i);
            ImprimePacotes(h->pacotes[i]);
        }
    }
}

Pacote *InitPacote(int nxtHop) {
    if (nxtHop < 0) return NULL;

    Pacote *new = malloc(sizeof(Pacote));
    new->nextHop = nxtHop;
    new->next = NULL;

    return new;
}

void LiberaPacote(Pacote *pacote) {
    if (!pacote) return;

    Pacote *auxiliar = pacote->next;
    while(auxiliar) {
        free(pacote);
        pacote = auxiliar;
        auxiliar = auxiliar->next;
    }

    free(pacote);
}

void ImprimePacotes(Pacote *pacote) {
    if (!pacote) return;
    printf("\t%d\n", pacote->nextHop);
    ImprimePacotes(pacote->next);
}
