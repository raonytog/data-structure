#include "nPilhas.h"

struct IndicePilha{
    int Topo, Base;
};

struct TipoPilhaMultipla {
    TipoItem *Item[MaxTam];
    IndicePilha Pilha[N];
};