#include "filiais.h"

typedef struct tFiliais {
    char * nome;

    int qtdEstoque, qtdProduto;
    tProduto ** produtos;
} tFiliais;

tFiliais * CriaFiliais(tProduto ** lp, int sizeLP) {
    tFiliais * f = malloc(sizeof(tFiliais));
    f->qtdProduto = sizeLP;
    char temp[100];
    printf("DIGITE O NOME DA FILIAL: ");
    scanf("%[^\n]%*c", temp);
    f->nome = strdup(temp);
    f->qtdEstoque = 0;
    f->produtos = malloc(sizeLP * sizeof(tProduto*));
    for (int i=0;i<sizeLP;i++) {
        f->produtos[i] = malloc(sizeof(tProduto*));
        f->produtos[i] = lp[i];
    }

    for (int i=0;i<sizeLP;i++) 
        AtribuiEstoqueProduto(f->produtos[i]);

    CalculaEstoqueFilial(f);
    printf("\n");

    return f;
}

void LiberaFiliais(tFiliais ** f, int sizeF) {

    for (int i=0;i<sizeF;i++) {
        free(f[i]);
    }
    free(f);
}

void ImprimeFilial (tFiliais * f) {
    printf("\tFILIAL: %s\n\tESTOQUE: %d\n", f->nome, f->qtdEstoque);
    for (int i = 0; i< f->qtdProduto; i++)
        ImprimeProduto(f->produtos[i]);
}

void CalculaEstoqueFilial (tFiliais * f) {
    for (int i = 0; i < f->qtdProduto; i++) {
        f->qtdEstoque += RetornaEstoqueProduto(f->produtos[i]) * RetornaPrecoProduto(f->produtos[i]);
    }
}

int ObtemEstoqueFilial (tFiliais * f) { 
    return f->qtdEstoque;
}