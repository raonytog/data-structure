#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "produto.h"

int main () {
    Sentinela * lista = CriaSentinela();

    Produto * batata = CriaProduto(001, "batata", 10);
    Produto * chocolate = CriaProduto(002, "chocolate", 20);

    InsereProdutoLista(lista, batata);
    ImprimeLista(lista);

    InsereProdutoLista(lista, chocolate);
    ImprimeLista(lista);

    LiberaLista(lista);
    return 0;
}