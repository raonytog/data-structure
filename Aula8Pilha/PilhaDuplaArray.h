#define MaxTam 1000

typedef int QualPilha;

typedef int TipoItem;

typedef struct IndicePilha IndicePilha;

typedef struct TipoPilhaDupla TipoPilhaDupla;

TipoPilhaDupla *init();

void Push(TipoPilhaDupla *pilha, TipoItem *item, int wichStack);

TipoItem *Pop(TipoPilhaDupla *pilha, QualPilha wichStack);

void Free(TipoPilhaDupla *pilha);
