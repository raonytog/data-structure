#include "filiais.h"

typedef struct tFiliais {
    char * nome;

    int qtdEstoque, qtdProduto;
    tProduto ** produtos;
} tFiliais;

tFiliais * CriaFiliais() {
    tFiliais * f = malloc(sizeof(tFiliais));
    f->qtdEstoque = 0;

    char temp[100];
    printf("DIGITE O NOME DA FILIAL: ");
    scanf("%[^\n]%*c", temp);
    f->nome = strdup(temp);

    printf("DIGITE A QTD DE PRODUTOS: ");
    scanf("%d%*c", &f->qtdProduto);

    f->produtos = malloc(f->qtdProduto * sizeof(tProduto*));
    for (int i = 0; i < f->qtdProduto; i++)
        f->produtos[i] = CriaProduto();

    CalculaEstoqueFilial(f);
    printf("\n");
    return f;
}

void LiberaFiliais(tFiliais * f) {
    free(f->nome);
    for (int i = 0; i< f->qtdProduto; i++)
        LiberaProduto(f->produtos[i]);
    free(f->produtos);
}

void ImprimeFilial (tFiliais * f) {
    printf("\tFILIAL: %s\n\tESTOQUE: %d\n", f->nome, f->qtdEstoque);
    for (int i = 0; i< f->qtdProduto; i++)
        ImprimeProduto(f->produtos[i]);
}

void CalculaEstoqueFilial (tFiliais * f) {
    for (int i = 0; i < f->qtdProduto; i++) {
        f->qtdEstoque += RetornaEstoqueProduto(f->produtos[i]);
    }
}

int ObtemEstoqueFilial (tFiliais * f) { 
    return f->qtdEstoque;
}