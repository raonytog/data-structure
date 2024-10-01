/** Raony Togneri Gomes */

#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree {
    char *palavra;
    int freq;
    Tree *left, *right;
};

Tree *InitTree() {
    return NULL;
}

Tree *InsertTree(Tree *treeNode, char *palavra) {
    if (!palavra) return NULL;

    if (!treeNode) {
        Tree *new = malloc(sizeof(Tree));
        new->freq = 1;
        new->left = new->right = NULL;
        new->palavra = strdup(palavra);
        return new;
    }

    if (strlen(palavra) > strlen(treeNode->palavra)) treeNode->right = InsertTree(treeNode->right, palavra);
    else treeNode->left = InsertTree(treeNode->left, palavra);

    return treeNode;
}

Tree *BinarySearch(Tree *treeNode, char *palavra) {
    if (!treeNode || !palavra) return NULL;

    if (strcmp(treeNode->palavra, palavra) == 0) return treeNode;

    if (strlen(palavra) > strlen(treeNode->palavra)) return BinarySearch(treeNode->right, palavra);
    else if (strlen(palavra) < strlen(treeNode->palavra)) return BinarySearch(treeNode->left, palavra);

    return NULL;
}

void incFrequencia(Tree *treeNode) {
    if (!treeNode) return;
    treeNode->freq++;
}

Tree *LiberaTree(Tree *treeNode) {
    if (!treeNode) return NULL;

    free(treeNode->palavra);
    LiberaTree(treeNode->left);
    LiberaTree(treeNode->right);
    free(treeNode);
}

Tree *PrintTree(Tree *treeNode) {
    printf("<");
    if (treeNode) {
        printf("%s %d ", treeNode->palavra, treeNode->freq);
        PrintTree(treeNode->left);
        PrintTree(treeNode->right);
    }
    printf(">");
}

int qtdPalavrasDistintas(Tree *treeNode) {
    if (!treeNode) return 0;

    int total = 1;
    return total + qtdPalavrasDistintas(treeNode->left) + qtdPalavrasDistintas(treeNode->right);
}

int qtdPalavrastotais(Tree *treeNode) {
    if (!treeNode) return 0;

    int total = treeNode->freq;
    return total + qtdPalavrastotais(treeNode->left) + qtdPalavrastotais(treeNode->right);
}

void PreencheVetor(Tree *arvore, Tree **vetor, int *atual) {
    if (arvore) {
        vetor[*atual] = arvore;
        (*atual)++;

        PreencheVetor(arvore->left, vetor, atual);
        PreencheVetor(arvore->right, vetor, atual);
    }
}

void PrintVetor(Tree *arvore, Tree **vetor, int size) {
    if (!vetor) return;

    FILE *fSaida = fopen("saida.txt", "w");

    qsort(vetor, size, sizeof(Tree*), ComparaFrequencia);
    for(int i = 0; i < size; i++) {
        printf("%s %d\n", vetor[i]->palavra, vetor[i]->freq);
        fprintf(fSaida, "%s %d\n", vetor[i]->palavra, vetor[i]->freq);
    }


    fprintf(fSaida, "------------------------\n");
    int qtdPalDistintas = qtdPalavrasDistintas(arvore);
    int qtdPaltotal = qtdPalavrastotais(arvore);
    Tree *maiorFreq = findMaiorFreq(arvore);

    fprintf(fSaida, "%d palavras distintas encontradas\n", qtdPalDistintas);
    fprintf(fSaida, "%d palavras no total\n", qtdPaltotal);
    fprintf(fSaida, "%s é a palavra de maior frequência (%d)\n", maiorFreq->palavra, maiorFreq->freq);
   
    fclose(fSaida);
}

int ComparaFrequencia(const void *a, const void *b) {
    Tree *new1 = *(Tree **)a;
    Tree *new2 = *(Tree **)b;
    
    if ((new1->freq - new2->freq) != 0) return new1->freq - new2->freq;
    else return ComparaAlfabetica(a, b);
}

int ComparaAlfabetica(const void *a, const void *b) {
    Tree *new1 = *(Tree **)a;
    Tree *new2 = *(Tree **)b;

    return strcmp(new1->palavra, new2->palavra);
}

Tree *max(Tree *n1, Tree *n2) {
    if (n1->freq > n2->freq) return n1;
    else if (n2->freq > n1->freq) return n2;
    else return n1;
}

Tree *findMaiorFreq(Tree *arvore) {
    if (!arvore) return NULL;

    return max(arvore, max(arvore->left, arvore->right));
}
