#ifndef _MERCADO_H_
#define _MERCADO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filiais.h"

typedef struct tSupermercado tSupermercado;


tSupermercado * CriaSupermercado(tProduto ** lp, int sizeLP);
void LiberaSuperMercado (tSupermercado * sm);
void ImprimeSuperMercado (tSupermercado * sm);

#endif 