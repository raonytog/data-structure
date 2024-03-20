#ifndef _FILIAIS_H_
#define _FILIAIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"

typedef struct tFiliais tFiliais;

tFiliais * CriaFiliais();
void LiberaFiliais(tFiliais * f);
void ImprimeFilial (tFiliais * f);
void CalculaEstoqueFilial (tFiliais * f);
int ObtemEstoqueFilial (tFiliais * f);

#endif 