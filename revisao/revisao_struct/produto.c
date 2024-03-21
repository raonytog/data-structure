#include "produto.h"

typedef struct tProduto {
    int valor;
    char * nome;
} tProduto;

tProduto ** CadastraListraDeProdutos() {
    tProduto ** lp;      char nomeProdTemp[100];

    int qtdProdTemp = 0, qtdProdReal = 0;
    printf("DIGITE QTD PRODUTOS QUER CADASTRAR");
    scanf("%d", &qtdProdTemp);  lp = malloc(qtdProdTemp * sizeof(tProduto*));
    
    int qtdProd = 0, val = 0;       scanf("%d", &qtdProd);
    for(int i=0;i<qtdProd;i++) {
        scanf("%[^,], %d", nomeProdTemp, &val);
        if (!EstaCadastradoProduto(nomeProdTemp, lp, qtdProdReal)) {
            lp[i] = CriaProduto(nomeProdTemp, val);
            qtdProdReal++;
        }
        else printf("PRODUTO JA CADASTRADO\n");
    }

    if (qtdProdReal != qtdProdTemp) realloc(lp, qtdProdReal);
    return lp;
}

tProduto * CriaProduto(char *s, int v) {
    tProduto * p = malloc(sizeof(tProduto));
    p->nome = strdup(s);
    p->valor = v;
    return p;
}

void LiberaProduto(tProduto * p) {
    free(p->nome);
    free(p);
}

void ImprimeProduto(tProduto * p) {
    printf("\t\tItem: %s, valor unitario: %d, quantidade: %d\n", p->nome, p->valor);
}

int EstaCadastradoProduto (char *s, tProduto **p, int qtdP) {
    for (int i=0;i<qtdP;i++) if (strcmp(s, p[i]->nome) == 0) return 1;
    return 0;
}