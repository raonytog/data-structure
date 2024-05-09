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
    if (!f) { printf("Fila nao alocada!\n"); return NULL; }

    f->first = f->last = NULL;
    return f;
}

void InsereFilaFinal(Fila *fila, Amostra *amostra) {
    if (!fila || !amostra) return;

    Celula *c = malloc(sizeof(Celula));
    c->amostra = amostra;
    c->next = NULL;

    // se n tiver item na fila
    if (!fila->first) { fila->first = fila->last = c;   return;}

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
    if (!fila || !fila->first) exit(EXIT_FAILURE);

    Amostra *requisitado = fila->first->amostra;
    
    if (!fila->first) return NULL;

    Celula *auxiliar = fila->first;
    fila->first = fila->first->next;
    if (fila->first == NULL) fila->last = NULL;
    free(auxiliar);

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
    while (auxilar) {
        auxilar = auxilar->next;
        liberaAmostra(fila->first->amostra);
        free(fila->first);
        fila->first = auxilar;
    }
    
    free(fila);
}

int EstaVaziaLista(Fila *fila) {
    if (!fila) return -1;
    if (!fila->first && !fila->last) return 1;
    return 0;
}