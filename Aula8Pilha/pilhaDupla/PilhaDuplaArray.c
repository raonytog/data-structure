#include "PilhaDuplaArray.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct IndicePilha {
    int Topo, Base;
};

struct TipoPilhaDupla{
    TipoItem *Item[MaxTam];
    IndicePilha Pilha1, Pilha2;
};

TipoPilhaDupla *init() {
    TipoPilhaDupla *pilha = malloc(sizeof(TipoPilhaDupla));
    pilha->Pilha1.Base = 0;   
    pilha->Pilha1.Topo = -1;

    pilha->Pilha2.Base = MaxTam - 1;
    pilha->Pilha2.Topo = MaxTam;

    return pilha;
}

void Push(TipoPilhaDupla *pilha, TipoItem item, QualPilha wichStack) {
    if (!pilha || (wichStack > 2 || wichStack < 1)) return;

    if (IsStackFull(pilha)) return;
    switch (wichStack) {
        case PILHA1:
            pilha->Item[pilha->Pilha1.Topo+1] = item;
            pilha->Pilha1.Topo++;
            break;

        case PILHA2:
            pilha->Item[pilha->Pilha2.Topo-1] = item;
            pilha->Pilha2.Topo--;
            break;
    }
    printf("Item '%d' has been pushed to the stack #%d!\n", item, wichStack);
}

TipoItem Pop(TipoPilhaDupla *pilha, QualPilha wichStack) {
    if (!pilha) return -999;

    TipoItem *popped;
    switch (wichStack) {
        case PILHA1:
            if (pilha->Pilha1.Topo == -1) return -999;
            popped = pilha->Item[pilha->Pilha1.Topo];
            pilha->Item[pilha->Pilha1.Topo] = 0;
            pilha->Pilha1.Topo--;
            break;

        case PILHA2:
            if (pilha->Pilha2.Topo == MaxTam -1) return -999;
            popped = pilha->Item[pilha->Pilha2.Topo];
            pilha->Item[pilha->Pilha2.Topo] = 0;
            pilha->Pilha2.Topo--;
            break;
    }

    printf("Item '%d' has been removed!\n", popped);
    return popped;
}

void DestroyStack(TipoPilhaDupla *pilha) {
    if (!pilha) return;
    free(pilha);
}

bool IsStackFull(TipoPilhaDupla *pilha) {
    if (!pilha) return true;
    if (pilha->Pilha1.Topo+1 + pilha->Pilha2.Topo+1 == MaxTam-1) return true;
    return false;
}

bool IsStackEmpity(TipoPilhaDupla *pilha) {
    if (!pilha) return true;
    if (pilha->Pilha1.Topo == -1 || pilha->Pilha2.Topo == MaxTam -1) return true;
    return false;
}

void PrintStack(TipoPilhaDupla *pilha) {
    if (!pilha) return;
    for (int i = 0; i < MaxTam; i++) {
        printf("%d - %d\n", i, pilha->Item[i]);
    }
}

