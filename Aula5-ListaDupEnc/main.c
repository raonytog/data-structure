#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "produto.h"

int main () {
    Celula *lista = CriaLista();

    Produto *batata = CriaProduto(001, "batata", 10);
    lista = InsereProdutoLista(lista, batata);
    ImprimeLista(lista);
    
    Produto *chocolate = CriaProduto(002, "chocolate", 20);
    lista = InsereProdutoLista(lista, chocolate);
    ImprimeLista(lista);

    Produto *queijo = CriaProduto(003, "queijo", 320);
    lista = InsereProdutoLista(lista, queijo);
    ImprimeLista(lista);

    lista = RetiraProdutoLista(002, lista);
    ImprimeLista(lista);

    LiberaProduto(batata);
    LiberaProduto(chocolate);
    LiberaProduto(queijo);

    LiberaLista(lista);
    return 0;
}