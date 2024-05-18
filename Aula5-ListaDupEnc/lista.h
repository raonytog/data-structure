#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"

typedef struct Celula Celula;

Celula* CriaLista();
void LiberaLista(Celula *lista);

void ImprimeLista(Celula *lista);
Celula* InsereProdutoLista(Celula *lista, Produto *p);
Celula* RetiraProdutoLista(int cod, Celula *lista);

#endif
