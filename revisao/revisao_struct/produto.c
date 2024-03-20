#include "produto.h"

typedef struct tProduto {
    int valor, qtdEstoqueItem;
    char * nome;
} tProduto;

tProduto * CriaProduto() {
    tProduto * p = malloc(sizeof(tProduto));

    printf("DIGITE O NOME, O VALOR E A QUANTIDADE DE ESTOQUE:\n");
    char temp[100];
    scanf("%[^,], %d, %d%*c", temp, &p->valor, &p->qtdEstoqueItem);
    p->nome = strdup(temp);
    printf("\n");
    return p;
}

void LiberaProduto(tProduto * p) {
    free(p->nome);
    free(p);
}

void ImprimeProduto(tProduto * p) {
    printf("\t\tItem: %s, valor unitario: %d, quantidade: %d\n", p->nome, p->valor, p->qtdEstoqueItem);
}

int RetornaEstoqueProduto(tProduto * p) {
    return p->qtdEstoqueItem * p->valor;
}