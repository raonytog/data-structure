#include "nPilhas.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct IndicePilha{
    int Topo, Base;
};

struct TipoPilhaMultipla {
    TipoItem *Item[MaxTam];
    IndicePilha Pilha[N];
};

TipoPilhaMultipla *Init() {
    TipoPilhaMultipla *stack = malloc(sizeof(TipoPilhaMultipla));

    for (int i = 0, base = 0; i < N; i++, base += 100) {
        stack->Pilha[i].Base = base;
        stack->Pilha[i].Topo = base-1;
    }

    return stack;
}

void PushStack(TipoPilhaMultipla *stack, TipoItem item, int wichStack) {
    if (!stack) return;

    if (!IsPushPossible(stack, wichStack)) return;
    stack->Pilha[wichStack].Topo++;
    int idx = stack->Pilha[wichStack].Topo;
    stack->Item[idx] = item;
}

TipoItem PopStack(TipoPilhaMultipla *stack, int wichStack) {
    if (!stack) return -1;
    if (IsStackEmpty(stack, wichStack)) return -1;

    TipoItem item = stack->Item[stack->Pilha[wichStack].Topo];
    stack->Item[stack->Pilha[wichStack].Topo] = 0;
    stack->Pilha[wichStack].Topo--;

    return item;
}

void DestroyStack(TipoPilhaMultipla *stack) {
    if (!stack) return;
    free(stack);
}

void PrintStack(TipoPilhaMultipla *stack) {
    if (!stack) return;

    for (int i = 0; i < N; i++) {
        printf("Stack #%d:\n", i);
        for (int j = stack->Pilha[i].Base; j < stack->Pilha[i].Topo+1; j++) {
            printf("  Content #%d: %d\n", j, stack->Item[j]);
        }
        printf("\n");
    }
}

int IsPushPossible(TipoPilhaMultipla *stack, int wichStack) {
    if (!stack) return -1;
    if (stack->Pilha[wichStack].Topo+1 >= stack->Pilha[wichStack].Base+100) return 0;
    return 1;
}

int IsStackEmpty(TipoPilhaMultipla *stack, int wichStack) {
    if (!stack) return -1;
    if (stack->Pilha[wichStack].Topo < stack->Pilha[wichStack].Base) return 1;
    return 0;
}

