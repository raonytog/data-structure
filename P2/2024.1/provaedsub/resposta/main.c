/** Raony Togneri Gomes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

int main() {
    FILE *fEntrada = fopen("entrada.txt", "r");
    Tree *arvore = InitTree();
    Tree *auxiliar = InitTree();

    char palavra[100];
    while (fscanf(fEntrada, "%s ", palavra) == 1) {
        auxiliar = BinarySearch(arvore, palavra);
        if (auxiliar) incFrequencia(auxiliar);
        else arvore = InsertTree(arvore, palavra);
    }
    
    int qtd = qtdPalavrasDistintas(arvore);
    int idx = 0;
    Tree **vetor = malloc(qtd * sizeof(Tree**));
    PreencheVetor(arvore, vetor, &idx);
    PrintVetor(arvore, vetor, qtd);

    free(vetor);

    LiberaTree(arvore);
    fclose(fEntrada);
    return 0;
}
