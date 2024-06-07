/**
 * Raony Togneri Gomes, 05 de julho, 2024 
 * UFES, Estrutura de Dados (3o semestre)
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Lista.h"

int main() {
    /** Cria a lista NULL */
    Lista *list = CriaLista();

    /** Insere os elementos na lista e imprime*/
    printf("Lista #1:\n");
    list = InsereLista(list, 10);
    list = InsereLista(list, 20);
    list = InsereLista(list, 30);
    list = InsereLista(list, 40);
    list = InsereLista(list, 50);
    list = InsereLista(list, 60);
    ImprimeLista(list);
    printf("\n");

    /** Retira elemento da lista e imprime */
    printf("Lista #2 (com retirada):\n");
    list = RetiraLista(list, 20);
    ImprimeLista(list);
    printf("\n");

    /** Libera a lista */
    LiberaLista(list);
    return 0;
}
