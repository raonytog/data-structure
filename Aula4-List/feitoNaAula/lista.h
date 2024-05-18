#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "produto.h"

typedef struct sentinela Sentinela;

typedef struct lista Lista;

Sentinela *CriaSentinela();

Lista *CriaLista(Produto *p);

int EhListaVazia(Sentinela *s);

void InsereProdutoLista(Sentinela *s, Produto *p);

void RetiraProdutoLista(Sentinela *s, int cod);

void ImprimeLista(Sentinela *s);

void LiberaSentinela(Sentinela *s);

void LiberaLista(Lista *l);


#endif