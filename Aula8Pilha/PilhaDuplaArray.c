#ifndef _PILHADUPLAARRAY_C_
#define _PILHADUPLAARRAY_C_

#include "PilhaDuplaArray.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PILHA1 1
#define PILHA2 2

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

void Push(TipoPilhaDupla *pilha, TipoItem *item, QualPilha wichStack) {
    if (!pilha || wichStack != 1 || wichStack != 2) return;

    switch (wichStack) {
        case PILHA1:
            if (pilha->Pilha1.Topo == MaxTam) return;
            pilha->Item[pilha->Pilha1.Topo] = item;
            break;

        case PILHA2:
            if (pilha->Pilha2.Topo == MaxTam) return;
            pilha->Item[pilha->Pilha2.Topo] = item;
            break;
    }
}

TipoItem *Pop(TipoPilhaDupla *pilha, QualPilha wichStack) {
    if (!pilha) return;

}

void Free(TipoPilhaDupla *pilha) {
    if (!pilha) return;
    free(pilha);
}

#endif
