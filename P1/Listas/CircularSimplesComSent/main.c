#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    Lista *lista = CriaLista();
    Push(lista, "Hello");
    Push(lista, "World");
    Push(lista, "ola");
    Push(lista, "atuamalaca");
    Push(lista, "teste? testando?");
    Imprime(lista);

    Pop(lista, "ola");
    Imprime(lista);

    Pop(lista, "atuamalaca");
    Pop(lista, "teste? testando?");
    Imprime(lista);

    Pop(lista, "Hello");
    Pop(lista, "World");
    Push(lista, "Adeus!");
    Imprime(lista);
    
    Libera(lista);
    return 0;
}