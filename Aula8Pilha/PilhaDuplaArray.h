#ifndef _PILHADUPLAARRAY_C_
#define _PILHADUPLAARRAY_C_


#define MaxTam 10

#include <stdbool.h>

#define PILHA1 1
#define PILHA2 2

typedef int QualPilha;

typedef int TipoItem;

typedef struct IndicePilha IndicePilha;

typedef struct TipoPilhaDupla TipoPilhaDupla;


TipoPilhaDupla *init();

void Push(TipoPilhaDupla *pilha, TipoItem item, int wichStack);

TipoItem Pop(TipoPilhaDupla *pilha, QualPilha wichStack);

void DestroyStack(TipoPilhaDupla *pilha);

bool IsStackFull(TipoPilhaDupla *pilha);

bool IsStackEmpity(TipoPilhaDupla *pilha);

void PrintStack(TipoPilhaDupla *pilha);

#endif