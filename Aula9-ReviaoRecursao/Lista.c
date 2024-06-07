/**
 * Raony Togneri Gomes, 05 de julho, 2024 
 * UFES, Estrutura de Dados (3o semestre)
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Lista.h"

struct Lista {
    int item;
    Lista *next;
};

Lista *CriaLista() {
    Lista *lista = NULL;
    return lista;
}

Lista *RetiraLista(Lista *lista, int item) {
    if (!lista) return NULL;

    if (lista->item == item) {
        Lista *auxiliar = lista;
        lista = lista->next;
        free(auxiliar);

    } else { 
        lista->next = RetiraLista(lista->next, item);
    }

    return lista;
}

Lista *InsereLista(Lista *lista, int item) {
    Lista *novo = malloc(sizeof(Lista));
    novo->item = item;
    novo->next = NULL;

    if (!lista) {
        lista = novo;
        return lista;
    }

    novo->next = lista;
    return novo;
}

void ImprimeLista(Lista *lista) {
    if (!lista) return;

    printf("%d\n", lista->item);
    ImprimeLista(lista->next);
}

void LiberaLista(Lista *lista) {
    if (!lista) return;
    Lista *auxiliar = lista->next;
    free(lista);

    if (auxiliar) LiberaLista(auxiliar);
}