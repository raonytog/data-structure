#include "listaDup.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula Celula;

struct Celula {
    int data;
    Celula *next, *previous;
};

struct Lista {
    Celula *first, *last;
};


Lista *Inic() {
    Lista *lista = malloc(sizeof(Lista));
    lista->first = lista->last = NULL;
    return lista;
}

void Push(Lista *list, int item) {
    if (!list);

    Celula *new = malloc(sizeof(Celula));
    new->data = item;
    new->previous = new->next = NULL;

    // se vazia
    if (!list->first && !list->last) {
        list->first = list->last = new;
        return;
    }

    // demais
    new->previous = list->last;
    list->last->next = new;
    list->last = new;
}

int PopItem(Lista *list, int item) {
    if (!list) return -999;


    // vazia
    if (!list->first && !list->last) return -999;

    // se tiver um item
    if (list->first == list->last) {
        free(list->first);
        list->first = list->last = NULL;
        return item;
    }

    // se for o primeiro item
    if (list->first->data == item) {
        Celula *auxiliar = list->first;
        auxiliar = auxiliar->next;
        auxiliar->previous = NULL;
        free(list->first);
        list->first = auxiliar;
        return item;
    }

    for (Celula *i = list->first; i; i = i->next) {
        if (i->data == item) {
            i->previous->next = i->next;
            i->next->previous = i->previous;
            free(i);
            return item;
        }
    }
}

void Destroy(Lista *list) {
    if (!list) return;

    Celula *auxiliar = list->first;
    while (auxiliar) {
        auxiliar = auxiliar->next;
        free(list->first);
        list->first = auxiliar;
    }
    free(list);
}

void PrintList(Lista *list) {
    if (!list) return;

    int j = 0;
    for (Celula *i = list->first; i; i = i->next) {
        printf("%d - %d\n", ++j, i->data);
    }
}