#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "produto.h"

int main () {
    Sentinela *lista = CriaSentinela();

    Produto *batata = CriaProduto(001, "batata", 10);
    InsereProdutoLista(lista, batata);
    ImprimeLista(lista);
    
    Produto *chocolate = CriaProduto(002, "chocolate", 20);
    InsereProdutoLista(lista, chocolate);
    ImprimeLista(lista);

    Produto *queijo = CriaProduto(003, "queijo", 320);
    InsereProdutoLista(lista, queijo);
    ImprimeLista(lista);

    RetiraProdutoLista(lista, 002);
    ImprimeLista(lista);

    LiberaSentinela(lista);

    LiberaProduto(batata);
    LiberaProduto(chocolate);
    LiberaProduto(queijo);

    return 0;
}