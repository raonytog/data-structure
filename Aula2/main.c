#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mercado.h"
#include "produto.h"

int main () {
    int sizeLP = 0;
    tProduto ** listaProdutos = CadastraListraDeProdutos(&sizeLP);

    tSupermercado * spm = CriaSupermercado(listaProdutos, sizeLP);
    ImprimeSuperMercado(spm);

    for (int i=0;i<sizeLP;i++) 
        LiberaProduto(listaProdutos[i]);
    free(listaProdutos);

    LiberaSuperMercado(spm);
    return 0;
}