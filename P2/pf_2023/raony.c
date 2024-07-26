#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

int main () {
    Tree *arvore = InitTree();

    FILE *fEntrada = fopen("entrada.txt", "r");
    int qtdArquivos = 0; char name[100], presenca;
    fscanf(fEntrada, "%*c %d", &qtdArquivos);
    while (fscanf(fEntrada, "%s", name) == 1) {
        arvore = InsertTree(arvore, name);
    }
    fclose(fEntrada);

    char endereco[100];
    for (int i = 0; i < qtdArquivos; i++) {
        sprintf(endereco, "entrada%d.txt", i+1);
        FILE *fEndereco = fopen(endereco, "r");
        while (fscanf(fEndereco, "%s %c", name, &presenca) == 2) {
            BinarySearch(arvore, name, presenca);
        }
        fclose(fEndereco);
    }
    PrintTree(arvore);

    FILE *fSaida = fopen("saida.txt", "w");
    PrintTreeFile(arvore, fSaida);
    fclose(fSaida);

    DestroyTree(arvore);
    return 0;
}