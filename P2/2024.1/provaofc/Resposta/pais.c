#include <string.h>
#include <stdlib.h>

#include "pais.h"

/**
 * Raony Togneri Gomes
*/

struct Pais {
    char *name;
    int ouro, prata, bronze, total;
};

Pais *InitPais(char *nome, int ouro, int prata, int bronze, int total) {
    if (!nome) return NULL;

    Pais *new = malloc(sizeof(Pais));
    new->name = strdup(nome);
    new->ouro = ouro;
    new->prata = prata;
    new->bronze = bronze;
    new->total = total;

    return new;
};

char *getPaisName(Pais *p) {
    if (!p) return '\0';
    return p->name;
}

void DestroyPais(Pais *p) {
    if (!p) return;
    free(p->name);
    free(p);

    p = NULL;
}

void PrintPais(Pais *p) {
    if (!p) return;
    printf("%s %d %d %d %d\n", p->name, p->ouro, p->prata, p->bronze, p->total);
}


void AtualizaInformacoesPais(Pais *p, int ouro, int prata, int bronze, int total) {
    if (!p) return;
    
    p->ouro = ouro;
    p->prata = prata;
    p->bronze = bronze;
    p->total = total;
}

int ComparaMedalhasOuro(const void *a, const void *b) {
    if (!a || !b) return 0;

    Pais *pa = (Pais*)a;
    Pais *pb = (Pais*)b; 
    if (pa->ouro - pb->ouro != 0) return pa->ouro - pb->ouro;
    else return ComparaMedalhasPrata(a, b);
}

int ComparaMedalhasPrata(const void *a, const void *b) {
    if (!a || !b) return 0;

    Pais *pa = (Pais*)a;
    Pais *pb = (Pais*)b; 
    if (pa->prata - pb->prata != 0) return pa->prata - pb->prata;
    else return ComparaMedalhasBronze(a, b);
}

int ComparaMedalhasBronze(const void *a, const void *b) {
    if (!a || !b) return 0;

    Pais *pa = (Pais*)a;
    Pais *pb = (Pais*)b; 
    return pa->bronze - pb->bronze;
}

void SortPaises(Pais **vetor, int size, FILE *arquivo) { 
    if (!vetor || size < 0) return;

    Pais v[size];
    for (int i = 0; i < size; i++)
        v[i] = *vetor[i];

    qsort(v, size, sizeof(Pais), ComparaMedalhasOuro);

    for (int i = size-1; i >= 0; i--) { 
        fprintf(arquivo, "%s %d %d %d %d\n", v[i].name, v[i].ouro, v[i].prata, v[i].bronze, v[i].total);
    }

}