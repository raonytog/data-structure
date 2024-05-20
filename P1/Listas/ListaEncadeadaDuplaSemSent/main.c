#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaDupSS.h"

int main() {
    Lista *lista;
    lista = Push(lista, 10);
    lista = Push(lista, 20);
    lista = Push(lista, 30);
    lista = Push(lista, 40);
    lista = Push(lista, 50);
    lista = Push(lista, 60);
    
    PopItem(lista, 10);

    PrintList(lista);
    Destroy(lista);
    
    return 0;
}
