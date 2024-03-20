#include "mercado.h"

typedef struct tSupermercado {
    int qtdEstoque, qtdFiliais;
    char * nome;
    tFiliais ** filiais;
} tSupermercado;

tSupermercado * CriaSupermercado() {
    tSupermercado * sm = malloc(sizeof(tSupermercado));
    char temp[100];
    printf("DIGITE O NOME DO SUPERMERCADO:\n");
    scanf("%[^\n]%*c", temp);
    sm->nome = strdup(temp);

    printf("DIGITE A QTD DE FILIAIS: ");
    scanf("%d%*c", &sm->qtdFiliais);

    sm->filiais = malloc(sm->qtdFiliais * sizeof(tFiliais*));
    for (int i = 0; i < sm->qtdFiliais; i++) {
        sm->filiais[i] = CriaFiliais();
        sm->qtdEstoque += ObtemEstoqueFilial(sm->filiais[i]);
    }
    printf("\n");
    return sm;
}

void LiberaSuperMercado (tSupermercado * sm) {
    free(sm->nome);
    for (int i = 0; i < sm->qtdFiliais; i++)
        LiberaFiliais(sm->filiais[i]);
    free(sm->filiais);
    free(sm);
}

void ImprimeSuperMercado (tSupermercado * sm) {
    printf("NOME: %s, ESTOQUE TOTAL: %d\n", sm->nome, sm->qtdEstoque);
    for (int i = 0; i < sm->qtdFiliais; i++) ImprimeFilial(sm->filiais[i]);
}