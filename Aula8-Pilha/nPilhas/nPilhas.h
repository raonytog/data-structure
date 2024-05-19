#ifndef _NPILHAS_H_
#define _NPILHAS_H_

#define MaxTam 1000
#define N 10

#define STACK1 0
#define STACK2 1
#define STACK3 2
#define STACK4 3
#define STACK5 4
#define STACK6 5
#define STACK7 6
#define STACK8 7
#define STACK9 8
#define STACK10 9


typedef int TipoItem;
typedef struct IndicePilha IndicePilha;
typedef struct TipoPilhaMultipla TipoPilhaMultipla;

TipoPilhaMultipla *Init();

void PushStack(TipoPilhaMultipla *stack, int item, int wichStack);

int PopStack(TipoPilhaMultipla *stack, int wichStack);

void DestroyStack(TipoPilhaMultipla *stack);

void PrintStack(TipoPilhaMultipla *stack);

int IsPushPossible(TipoPilhaMultipla *stack, int wichStack);

int IsStackEmpty(TipoPilhaMultipla *stack, int wichStack);

#endif // !_NPILHAS_H_