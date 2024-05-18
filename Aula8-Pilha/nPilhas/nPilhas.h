#ifndef _NPILHAS_H_
#define _NPILHAS_H_

#define MaxTam 1000
#define N 10

typedef int TipoItem;
typedef struct IndicePilha IndicePilha;
typedef struct TipoPilhaMultipla TipoPilhaMultipla;

TipoPilhaMultipla *Init();

void PushStack(TipoPilhaMultipla *stack, TipoItem item, int wichStack);

TipoItem PopStack(TipoPilhaMultipla *stack, TipoItem item, int wichStack);

void DestroyStack(TipoPilhaMultipla *stack);

#endif // !_NPILHAS_H_