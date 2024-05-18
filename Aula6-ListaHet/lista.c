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
    if (!c) return;

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
    lista->last = c;
    return;
}

/**
 * O maior problema que tive foi nesta funcao, pois eu esqueci de liberar a celula. 
 * Alem disso, tambem esqueci de retornar no primeiro if, pois ele sempre ia ao while
 * ja que estava sem o if
*/
void RetiraDaLista(Lista *lista, void *animal) {
    if (!animal || !lista || !lista->first) return;
    Celula *aux = lista->first, *ant = NULL;

    // se for o primeiro
    if (aux->animal == animal) {
        lista->first = aux->prox;
        free(aux);

        // se a lista so tiver um item
        if (!lista->first) 
            lista->last = NULL;

        return;
    }
    

    // Procura o elemento a ser removido
    while (aux) {
        if (aux->animal == animal) {
            ant->prox = aux->prox;
            
            // Se for o último item da lista
            if (aux == lista->last)
                lista->last = ant;
                
            free(aux);
            return;
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