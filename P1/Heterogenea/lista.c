#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Gato.h"
#include "Cachorro.h"

typedef struct Celula Celula;
struct Celula {
    int tipo;
    void *animal;
    Celula *next;
    Celula *previous;
};

struct Lista {
    Celula *first, *last;
};

Lista *CriaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->first = l->last = NULL;
    return l;
}

void InsereLista(Lista *lista, void *animal, int tipo) {
    if (!lista || !animal) return;

    Celula *novo = malloc(sizeof(Celula));
    novo->animal = animal;
    novo->tipo = tipo;
    novo->previous = novo->next = NULL;

    if (!lista->first && !lista->last) {
        lista->first = lista->last = novo;
        return;
    }

    lista->last->next = novo;
    novo->previous = lista->last;
    lista->last = novo;
}

void RetiraLista(Lista *lista, void *animal) {
    if (!lista || !animal) return;

    if (!lista->first && !lista->last) return;

    Celula *auxiliar = lista->first, *ant = NULL;
    if (lista->first->animal == animal) { 
        lista->first = lista->first->next;
        free(auxiliar);
        
        if (!lista->last) {
            lista->last = NULL;
        }

        return;
    }

    auxiliar = lista->first;
    while (auxiliar) {
        if (auxiliar->animal == animal) {
            ant->next = auxiliar->next;
            auxiliar->next->previous = ant;
            free(auxiliar);
            return;
        }
        ant = auxiliar;
        auxiliar = auxiliar->next;
    }
}

void ImprimeLista(Lista *lista) {
    if (!lista) return;

    Celula *auxiliar = lista->first;
    while (auxiliar) {
        switch (auxiliar->tipo) {
            case GATO:
                imprimeGato(auxiliar->animal);
                break;

            case CACHORRO:
                imprimeCachorro(auxiliar->animal);
                break;
        

        }
        auxiliar = auxiliar->next;
    }
}

void LiberaLista(Lista *lista) {
    if (!lista) return;

    Celula *auxiliar = lista->first;
    while (auxiliar) {
        auxiliar = auxiliar->next;
        free(lista->first);
        lista->first = auxiliar;
    }
    free(lista);
}

int RetornaQtdCachorros(Lista *lista) {
    if (!lista) return 0;

    int qtd = 0;
    Celula *aux = lista->first;
    for (;aux;) {
        if (aux->tipo == CACHORRO) qtd++;
        aux = aux->next;
    }

    return qtd;
}

int RetornaQtdGatos(Lista *lista) {
    if (!lista) return 0;

    int qtd = 0;
    Celula *aux = lista->first;
    for (;aux;) {
        if (aux->tipo == GATO) qtd++;
        aux = aux->next;
    }

    return qtd;
}