#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tProduto tProduto;

tProduto ** CadastraListraDeProdutos(int *sizeLP);
tProduto * CriaProduto(char *s);
void LiberaProduto (tProduto * p);
void ImprimeProduto(tProduto * p);
int EstaCadastradoProduto (char *s, tProduto **p, int qtdP);
int RetornaEstoqueProduto(tProduto *p);
int RetornaPrecoProduto(tProduto *p);
void AtribuiValorProduto(tProduto *p);
void AtribuiEstoqueProduto(tProduto *p);

#endif