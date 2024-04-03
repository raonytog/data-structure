#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct produto Produto;

Produto * CriaProduto(int cod, char *nome, float preco);

int GetCodigoProduto(Produto *p);

char* GetNomeProduto(Produto *p);

float GetPrecoProduto(Produto *p);

void ImprimeProduto(Produto *p);

void LiberaProduto(Produto *p);


#endif