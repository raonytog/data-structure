#include "Lista.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Lista {
    int item;
    Lista *next;
};

Lista *CriaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->next = NULL;
    return lista;
}

Lista *RetiraLista(Lista *lista, int item) {
    if (!lista) return NULL;

    if (lista->item == item) {
        Lista *auxiliar = lista;
        lista = auxiliar;
        free(auxiliar);

    } else { 
        lista->next = RetiraLista(lista, item);
    }
}

Lista *InsereLista(Lista *lista, int item) {
    if (!lista) return NULL;

    Lista *novo = malloc(sizeof(Lista));
    novo->item = item;
    novo->next = lista;

    return novo;
}

void ImprimeLista(Lista *lista) {
    if (!lista) return

    printf("%d\n", lista->item);
    ImprimeLista(lista->next);
}