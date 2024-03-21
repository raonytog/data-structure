#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mercado.h"
#include "produto.h"

int main () {
    tProduto ** listaProdutos = CadastraListraDeProdutos();
    tSupermercado * spm = CriaSupermercado(listaProdutos);
    ImprimeSuperMercado(spm);
    LiberaSuperMercado(spm);
    return 0;
}