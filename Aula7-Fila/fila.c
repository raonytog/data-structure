#include "fila.h"

typedef struct Celula Celula;

struct Celula {
    Amostra *amostra;
    Celula* next;
};

struct Fila {
    Celula *first, *last;
};

Fila *IniciaFila() {
    Fila *f = malloc(sizeof(Fila));
    if (!f) {
        printf("Fila nao alocada!\n"); return NULL;
    }

    f->first = f->last = NULL;
    return f;
}

void InsereFilaFinal(Fila *fila, Amostra *amostra) {
    if (!fila || !amostra) return;

    Celula *c = malloc(sizeof(Celula));
    c->amostra = amostra;
    c->next = NULL;

    // se n tiver item na fila
    if (!fila->first) {
        fila->first = fila->last = c;
        return;
    }

    fila->last->next = c;
    fila->last = c;

}

void InsereFilaInicio(Fila *fila, Amostra *amostra) {
    if (!fila || !amostra) return;

    Celula *c = malloc(sizeof(Celula));
    c->amostra = amostra;
    c->next = NULL;

    if (!fila->first) {
        fila->first = fila->last = c;
        return;
    }

    c->next = fila->first;
    fila->first = c;
}

Amostra *RetiraFila(Fila *fila) {
    if (!fila || !fila->first) return NULL;

    Amostra *requisitado; Fila *fila;
    if (fila->first == fila->last) {
        requisitado = fila->first->amostra;
        free(fila->first);
        fila->first = fila->last = NULL;
        return requisitado;
    }

    requisitado = fila->first->amostra;
    free(fila->first);
    fila->first = fila->first->next;
    return requisitado;
}

void ImprimeFila(Fila *fila) {
    if (!fila) return;
    Celula *auxilar = fila->first;
    for (;auxilar;) {
        imprimeAmostra(auxilar->amostra);
        auxilar = auxilar->next;
    }
}

void Liberafila(Fila *fila) {
    if (!fila) return;
    Celula *auxilar = fila->first;
    for (;auxilar; fila->first = auxilar) {
        auxilar = auxilar->next;
        free(fila->first);
    }
}