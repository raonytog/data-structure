#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tProduto tProduto;

tProduto * CriaProduto();
void LiberaProduto (tProduto * p);
void ImprimeProduto(tProduto * p);
int RetornaEstoqueProduto(tProduto * p);

#endif