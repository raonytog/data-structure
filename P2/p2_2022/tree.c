
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findASCII(char *string) {
    int total = 0;
    for (int i = 0; i < strlen(string); i++) {
        total += string[i];
    }

    return total;
}


#include "tree.h"

struct Tree {
    char *palavra;
    Tree *left, *right;
};

Tree *InitTree() {
    return NULL;
}

Tree *InsertOnTree(Tree *arv, char *palavra) {
    if (!palavra) return NULL;

    /** Arvore vazia */
    if (arv == NULL) {
        Tree *new = malloc(sizeof(Tree));
        new->palavra = strdup(palavra);
        new->left = new->right = NULL;
        return new;
    }

    int novo = findASCII(palavra);
    int atual = findASCII(arv->palavra);

    if (novo < atual) arv->left = InsertOnTree(arv->left, palavra);
    else arv->right = InsertOnTree(arv->right, palavra);
    
    return arv;
}

void DestroyTree(Tree *arv) {
    if (!arv) return;    
}

void PrintTree(Tree *arv) {
    printf("<");

    if (arv) {
        printf("%s ", arv->palavra);
        PrintTree(arv->left);
        PrintTree(arv->right);
    }

    printf(">");
}

int get_qtd_nodes(Tree *arv) {
    if (!arv) return 0;
    
    int total = 1;
    total += get_qtd_nodes(arv->right);
    total += get_qtd_nodes(arv->left);

    return total;
}

int get_frequencia_palavra(Tree *arv, char *palavra) {
    if (!arv) return 0;

    int total = 0;
    if (strcmp(arv->palavra, palavra) == 0) total++;
    total += get_frequencia_palavra(arv->right, palavra);
    total += get_frequencia_palavra(arv->left, palavra);
    return total;
}

void preenche_palavras_distintas(Tree *arvore, char **palavras, int *idx) {
    if (!arvore) return;

    if (get_frequencia_palavra(arvore, arvore->palavra) == 1) {
        int achou = 0;
        for (int i = 0; i < *idx; i++) {
            if (strcmp(palavras[i], arvore->palavra) == 0) 
                achou = 1;
        }

        if (!achou) {
            strcpy(palavras[*idx], arvore->palavra);
            (*idx)++;
        }
    }
    preenche_palavras_distintas(arvore->right, palavras, idx);
    preenche_palavras_distintas(arvore->left, palavras, idx);
}