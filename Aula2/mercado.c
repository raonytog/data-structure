#include "mercado.h"

typedef struct tSupermercado {
    int qtdEstoque, qtdFiliais;
    char * nome;
    tFiliais ** filiais;
} tSupermercado;

tSupermercado * CriaSupermercado(tProduto **lp, int sizeLP) {
    tSupermercado * sm = malloc(sizeof(tSupermercado));

    printf("Digite o nome do super mercado:\n");
    char temp[100];
    scanf("%[^\n]%*c", temp);
    sm->nome = strdup(temp);
    printf("\n");

    printf("Digite a qtd de filiais: ");
    scanf("%d%*c", &sm->qtdFiliais);

    sm->filiais = malloc(sm->qtdFiliais * sizeof(tFiliais*));
    for (int i = 0; i < sm->qtdFiliais; i++) {
        sm->filiais[i] = CriaFiliais(lp, sizeLP);
        sm->qtdEstoque += ObtemEstoqueFilial(sm->filiais[i]);
    }
    printf("\n");
    return sm;
}

void LiberaSuperMercado (tSupermercado * sm) {
    free(sm->nome);
    LiberaFiliais(sm->filiais, sm->qtdFiliais);
    free(sm);
}

void ImprimeSuperMercado (tSupermercado * sm) {
    printf("NOME: %s, ESTOQUE TOTAL: %d\n", sm->nome, sm->qtdEstoque);
    for (int i = 0; i < sm->qtdFiliais; i++) ImprimeFilial(sm->filiais[i]);
}