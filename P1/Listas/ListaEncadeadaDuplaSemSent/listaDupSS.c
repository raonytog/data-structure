#include "listaDupSS.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lista {
    int data;
    Lista *next;
};

Lista *Push(Lista *list, int item) {
    if (!list) return NULL;

    Lista *new = malloc(sizeof(Lista));
    new->data = item;
    new->next = NULL;

    list->next = new;    
    return new;
}

Lista *PopItem(Lista *list, int item) {
    if (!list) return NULL;

    // se a primeira
    if (list->data == item) {
        Lista *new = list->next;
        free(list);
        return new;
    }

    // demais
    Lista *auxiliar = list, *ant = NULL;
    while (auxiliar) {
        if (auxiliar->data == item) {
            ant->next = auxiliar->next;
            free(auxiliar);
            return list;
        }
        ant = auxiliar;
    }
}

void Destroy(Lista *list) {
    if (!list) return;

    Lista *auxiliar = list;
    while (auxiliar) {
        auxiliar = auxiliar->next;
        free(list);
        list = auxiliar;
    }
}

void PrintList(Lista *list) {
    if (!list) return;

    Lista *auxiliar = list; int cont = 0;
    while (auxiliar) {
        printf("%d - %d\n", ++cont, list->data);
        auxiliar = auxiliar->next;
    }
}