#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula Celula;

struct Celula {
    char *palavra;
    Celula *next;
};

struct Lista {
    Celula *first, *last;
};

Lista *CriaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->first = l->last = NULL;
    return l;
}

void Push(Lista *lista, char *palavra) {
    if (!lista || !palavra) return;

    Celula *nova = malloc(sizeof(Celula));
    nova->palavra = strdup(palavra);
    nova->next = NULL;

    if (!lista->first && !lista->last) {
        lista->first = lista->last = nova;
        return;
    }

    nova->next = lista->first;
    lista->last->next = nova;
    lista->last = nova;
}

void Pop(Lista *lista, char *palavra) {
    if (!lista || !palavra) return;

    Celula *auxiliar = NULL, *ant = NULL, *temp = NULL;
    // se for o primeiro
    if (strcmp(lista->first->palavra, palavra) == 0) {
        auxiliar = lista->first;
        lista->last->next = lista->first->next;
        lista->first = lista->first->next;

        free(auxiliar->palavra);
        free(auxiliar);

        // se for unico
        if (!lista->last) 
            lista->last = NULL;

        return;
    }

    // demais
    auxiliar = lista->first->next;
    while (auxiliar != lista->first) {
        if (strcmp(auxiliar->palavra, palavra) == 0) {
            temp = auxiliar;
            ant->next = auxiliar->next;
            auxiliar = auxiliar->next;
            free(temp->palavra);
            free(temp);

        } else {
            ant = auxiliar;
            auxiliar = auxiliar->next;
        }
    }
}

void Libera(Lista *lista) {
    if (!lista) return;

    Celula *auxiliar = lista->first->next, *secundario = NULL;
    if (lista->first) {
        while (auxiliar != lista->first) {
            secundario = auxiliar;
            auxiliar = auxiliar->next;
            free(secundario->palavra);
            free(secundario);
        }
        free(lista->first->palavra);
        free(lista->first);
    }
    free(lista);
}

void Imprime(Lista *lista) {
    if (!lista) return;

    if (lista->first) {
        printf("%s\n", lista->first->palavra);

        Celula *auxiliar = lista->first->next;
        while (auxiliar != lista->first) {
            printf("%s\n", auxiliar->palavra);
            auxiliar = auxiliar->next;
        }
    }
    printf("\n");
}
