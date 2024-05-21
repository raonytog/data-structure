#include "fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila {
    int *data[MAX];
    int inicio, fim, qtdAtual;
};

Fila* cria_fila(void) {
    Fila *f = malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = -1;
    f->qtdAtual = 0;
    return f;
}

void insere (int data, Fila* f) {
    if (!f) return;
    
    if (f->qtdAtual == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    if (f->fim == MAX-1) f->fim = -1;

    f->fim++;
    f->data[f->fim] = data;
    f->qtdAtual++;
}

int retira (Fila* f) {
    if (!f) return -1;

    if (Vazia_fila(f)) return -1;

    int item = f->data[f->inicio];
    f->data[f->inicio] = 0;

    if (f->inicio+1 == MAX-1) f->inicio = 0;
    else f->inicio++;

    f->qtdAtual--;
    return item;
}

void imprime_fila (Fila* f) {
    if (!f) return;
    
    printf ("---------- Imprime fila-----------\n");
    for (int cont = 0, i = f->inicio; cont < f->qtdAtual; cont++) {
        if (i == MAX) i = 0;

        printf("%d - %d\n", cont+1, f->data[i]);
        i++;
    }
    printf("\n");
}

int Vazia_fila (Fila* f) { return f->qtdAtual == 0; }

void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores) {
    if (!f) return;

    for (int cont = 0, i = f->inicio; cont < f->qtdAtual; cont++, i++) {
        if (i == MAX) i = 0;

        if (f->data[i] >= 60) insere(f->data[i], f_maiores);
        else insere(f->data[i], f_menores);
    }
}   

Fila* destroi_fila (Fila* f) {
    if (!f) return NULL;
    free(f);
    return f;
}