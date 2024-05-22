#include "listaVetor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lista {
    int *data[MAX];
    int first, last, realSize;
};

Lista *Inic() {
    Lista *l = malloc(sizeof(Lista));
    l->first = 0; 
    l->last = MAX-1;
    l->realSize = 0;
    return l;
}

void Push(Lista *list, int item) {
    if (!list) return;

    if (list->realSize == 0) {
        list->data[0] = item;
        list->realSize++;
        return;
    }

    if (list->realSize <= list->last) {
        list->data[list->realSize] = item;
        list->realSize++;
        return;
    }
    
}

int PopItem(Lista *list, int item) {
    if (!list) return -999;

    for (int i = 0; i < list->last; i++) {
        if (item == list->data[i]) {
            list->data[i] = -999;
            return list->data[i];
        }
    }
}

void Destroy(Lista *list) {
    if (list) free(list);
}

void PrintList(Lista *list) {
    if (!list) return;

    for (int i = 0; i < list->last; i++)
        printf("%d - %d\n", i+1, list->data[i]);

}