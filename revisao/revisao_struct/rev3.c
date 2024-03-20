#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mercado.h"

int main () {
    printf("Vamos criar um super mercado!\n");
    tSupermercado * spm = CriaSupermercado();
    ImprimeSuperMercado(spm);
    LiberaSuperMercado(spm);
    return 0;
}