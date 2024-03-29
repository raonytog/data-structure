#include "produto.h"

typedef struct tProduto {
    int valor, qtd;
    char * nome;
} tProduto;

tProduto ** CadastraListraDeProdutos(int *sizeLP) {
    int qtdProdTemp = 0, qtdProdReal = 0, price = 0;

    printf("Digite a qtd de produtos: ");
    scanf("%d%*c", &qtdProdTemp);
    tProduto ** lp = malloc(qtdProdTemp * sizeof(tProduto*));

    char nomeProdTemp[100];
    for(int i=0;i<qtdProdTemp;i++) {
        printf("Digite o nome do produto: ");   scanf("%[^\n]%*c", nomeProdTemp);
        if (!EstaCadastradoProduto(nomeProdTemp, lp, qtdProdReal)) {
            lp[qtdProdReal] = malloc(sizeof(tProduto*));
            lp[qtdProdReal]->nome = strdup(nomeProdTemp);

            printf("\tDigite o preco de/da %s: ", lp[qtdProdReal]->nome); scanf("%d%*c", &price);
            lp[qtdProdReal]->valor = price;
            
            qtdProdReal++;
        }
        else printf("Produto ja cadastrado\n");
    }

    if (qtdProdReal != qtdProdTemp) lp = realloc(lp, qtdProdReal);
    *sizeLP = qtdProdReal;
    printf("\n\n");
    return lp;
}

tProduto * CriaProduto(char *s) {
    tProduto * p = malloc(sizeof(tProduto));
    p->nome = strdup(s);
    return p;
}

void LiberaProduto(tProduto * p) {
    free(p);
}

void ImprimeProduto(tProduto * p) {
    printf("\t\tItem: %s, valor unitario: %d, quantidade: %d\n", p->nome, p->valor, p->qtd);
}

int EstaCadastradoProduto (char *s, tProduto **p, int qtdP) {
    for (int i=0;i<qtdP;i++) if (strcmp(s, p[i]->nome) == 0) return 1;
    return 0;
}

int RetornaEstoqueProduto(tProduto *p) {
    return p->qtd;
}

int RetornaPrecoProduto(tProduto *p) {
    return p->valor;
}

void AtribuiEstoqueProduto(tProduto *p) {
    int stock = 0;
    printf("\tDigte o estoque do produto %s: ", p->nome);    scanf("%d%*c", &stock);
    p->qtd = stock;
}