#include "lista.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Gato.h"
#include "Cachorro.h"

typedef struct Celula Celula;

struct Lista {
    Celula *first;
    Celula *last;
};

struct Celula {
    int tipo;
    void *animal;
    Celula *prox;
};

Lista *IniciaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->first = NULL;
    l->last = NULL;
    return l;
}

void InsereNaLista(Lista *lista, void *animal, int tipo) {
    if (!animal || !lista) return;
    Celula *c = malloc(sizeof(Celula));
    c->animal = animal;
    c->tipo = tipo;
    c->prox = NULL;

    // lista vazia
    if (!lista->first && !lista->last) {
        lista->first = lista->last = c;
        return;
    }

    // mais itens
    lista->last->prox = c;
    lista->last = lista->last->prox;
    return;
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
            break;
        }

        ant = aux;
        aux = aux->prox;
    }
}

void ImprimeLista(Lista *lista) {
    if (!lista->first && !lista->last) return;

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
        
        aux = aux->prox;
    }
}

void LiberaLista(Lista *lista) {
    Celula *aux;
    while (lista->first) {
        aux = lista->first->prox;
        free(lista->first);
        lista->first = aux;
    }

    free(lista);
}

int RetornaQtdGatos(Lista *lista) {
    if (!lista) return 0;

    int qtd = 0;
    Celula *aux = lista->first;
    for (;aux;) {
        if (aux->tipo == GATO) qtd++;
        aux = aux->prox;
    }

    return qtd;
}

int RetornaQtdCachorros(Lista *lista) {
    if (!lista) return 0;

    int qtd = 0;
    Celula *aux = lista->first;
    for (;aux;) {
        if (aux->tipo == CACHORRO) qtd++;
        aux = aux->prox;
    }

    return qtd;
}