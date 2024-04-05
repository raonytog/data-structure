#include "produto.h"

struct produto {
    int cod;
    float preco;
    char *nome;
};

Produto * CriaProduto(int cod, char *nome, float preco) {
    Produto * p = malloc(sizeof(Produto));
    p->cod = cod;
    p->nome = strdup(nome);
    p->preco = preco;
    return p;
}

int GetCodigoProduto(Produto *p) {
    return p->cod;
}

char* GetNomeProduto(Produto *p) {
    return p->nome;
}

float GetPrecoProduto(Produto *p) {
    return p->preco;
}

void ImprimeProduto(Produto *p) {
    printf("Nome: %s, Preco: %.2ff, Codigo: %d\n", p->nome, p->preco, p->cod);
}

void LiberaProduto(Produto *p) {
    free(p->nome);
    free(p);
}
