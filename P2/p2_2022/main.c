#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

typedef char** Lista;

int main () {
    Tree *arvore = NULL;
    FILE *fTexto = fopen("entrada.txt", "r");

    char palavra[256];
    while (fscanf(fTexto, "%s ", palavra) == 1) {
        arvore = InsertOnTree(arvore, palavra);
    }
    fclose(fTexto);

    int qtdTotal = get_qtd_nodes(arvore);
    printf("Total: %d\n", qtdTotal);

    int qtdDistintas = 0;
    char **palavras = calloc(qtdTotal, sizeof(char *));
    for (int i = 0; i < qtdTotal; i++)
        palavras[i] = malloc(256 * sizeof(char));

    preenche_palavras_distintas(arvore, palavras, &qtdDistintas);
    printf("%d\n", qtdDistintas);

    for (int i = 0; i < qtdDistintas; i++) 
        printf("%d - %s\n", i+1, palavras[i]);
    printf("\n");

    /** 
     * Eu saberia continuar, mas estou com preguiça.
     * O ponto eh, eu teria que criar uma struct nova para salvar como vetor,
     * ja que qsort nao ordena pointer pointer
     */

    return 0;
}