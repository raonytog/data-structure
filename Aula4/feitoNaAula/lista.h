#ifndef _LISTA_H_
#define _LISTA_H_

#include "produto.h"

typedef struct sentinela Sentinela;

typedef struct lista Lista;

Sentinela * CriaSentinela();

Lista * CriaLista();

void InsereProdutoLista(Sentinela *s, Produto *p);

void RetiraProdutoLista(Sentinela *s, int cod);

void ImprimeLista(Sentinela *s);

void LiberaLista(Sentinela *s);


#endif