#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Lista.h"

int main() {
    Lista *list = CriaLista();
    InsereLista(list, 10);
    InsereLista(list, 20);
    InsereLista(list, 30);
    InsereLista(list, 40);
    InsereLista(list, 50);
    InsereLista(list, 60);
    ImprimeLista(list);

    RetiraLista(list, 20);
    ImprimeLista(list);

    LiberaLista(list);
    return 0;
}
