#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaDup.h"

int main() {
    Lista *lista = Inic();
    Push(lista, 10);
    Push(lista, 20);
    Push(lista, 30);
    Push(lista, 40);
    Push(lista, 50);
    Push(lista, 60);
    
    PopItem(lista, 10);

    PrintList(lista);
    Destroy(lista);
    
    return 0;
}
