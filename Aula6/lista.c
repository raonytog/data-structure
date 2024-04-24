#include "lista.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Gato.h"
#include "Cachorro.h"

#define CACHORRO 1
#define GATO 2

// bravo = 0
// agressivo = 1

struct Celula {
    int tipo;
    void *animal;
    Celula *prox;
};

typedef struct Celula Celula;

struct Lista {
    Celula *first;
    Celula *last;
};

Lista *IniciaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->first = NULL;
    l->last = NULL;
    return l;
}

void InsereNaLista(Lista *lista, void *animal) {
    if (!animal || !lista) return;
    Celula *c = malloc(sizeof(Celula));
    c->animal = animal;
    c->prox = NULL;

    // lista vazia
    if (!lista->first && !lista->last) {
        lista->first = lista->last = c;
        return lista;

    // um item
    } else {
        lista->last = c;
    }

    return c;
}

void RetiraDaLista(Lista *lista, void *animal) {
    if (!animal || !lista || ( !lista->first && !lista->last)) return;

    // lista com um item
    if (lista->first->animal == lista->last->animal) {
        lista->first = lista->last = NULL;
        return;
    }

    // se for o primeiro
    if (lista->first->animal == animal) {
        lista->first = lista->first->prox;
        return;
    }

    // os demais
    Celula *aux = lista->first, *ant;
    while (aux) {
        if (aux->animal == animal) {
            ant->prox = aux->prox;
        }

        ant = aux;
        aux = aux->prox;
    }
}

void ImprimeLista(Lista *lista) {
    if (!lista) return;

    Celula *aux = lista->first;
    while (aux) {
        switch (aux->tipo) {
            case CACHORRO:
                imprimeCachorro(aux->animal);
                break;

            case GATO:
                imprimeGato(aux->animal);
                break;
        }
    }
}

void LiberaLista(Lista *lista) {
    Celula *aux;
    while (lista->first) {
        aux = lista->first->prox;
        free(lista->first);
    }

    free(lista);
}


