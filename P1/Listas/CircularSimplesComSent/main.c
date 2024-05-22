#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    Lista *lista = CriaLista();
    Push(lista, "Hello");
    Push(lista, "World");
    Push(lista, "ola");
    Imprime(lista);

    Pop(lista, "ola");
    Imprime(lista);

    Libera(lista);
    return 0;
}