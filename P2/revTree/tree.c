#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree {
    char *word;
    Tree *left, *right;
};

Tree *InitTree() {
    return NULL;
}

Tree *InsertOnTree(Tree *treeNode, char *word) {
    if (!word) return NULL;

    if (!treeNode) {
        Tree *new = malloc(sizeof(Tree));
        new->word = strdup(word);
        new->right = new->left = NULL;
        return new;
    }

    if (strlen(word) > strlen(treeNode->word)) 
        treeNode->right = InsertOnTree(treeNode->right, word);

    else 
        treeNode->left = InsertOnTree(treeNode->left, word);

    return treeNode;
}

Tree *RemoveFromTree(Tree *treeNode, char *word) {
    if (!treeNode || !word) return NULL;

    if (strlen(treeNode->word) < strlen(word)) 
        treeNode->right = RemoveFromTree(treeNode->right, word);

    else if (strlen(word) < strlen(treeNode->word))
        treeNode->left = RemoveFromTree(treeNode->left, word);

    /** Caso 1: 0 filhos */
    if (treeNode->left == NULL && treeNode->right == NULL) {
        free(treeNode->word);
        free(treeNode);
        treeNode = NULL;
    }

    /** Caso 2: 1 filho */
    else if (treeNode->left == NULL) {
        Tree *auxiliar = treeNode->right;
        treeNode = auxiliar;
        free(auxiliar->word);
        free(auxiliar);
    }

    else if (treeNode->right == NULL) {
        Tree *auxiliar = treeNode->left;
        treeNode = auxiliar;
        free(auxiliar->word);
        free(auxiliar);
    }

    /** Caso 3: 2 filhos */
    else {
        Tree *auxiliar = treeNode->left;
        while (auxiliar->right) auxiliar = auxiliar->right;

        char reserva[100]; strcpy(reserva, treeNode->word);
        treeNode->word = auxiliar->word;
        auxiliar->word = reserva;
        treeNode->left = RemoveFromTree(treeNode->left, word);
    }

    return treeNode;

}

Tree *SearchOnTree(Tree *treeNode, char *word) {
    if (!treeNode || !word) return NULL;

    if (strcmp(treeNode->word, word) == 0)
        return treeNode;

    if (strcmp(word, treeNode->word) == 1) return SearchOnTree(treeNode->right, word);
    else return SearchOnTree(treeNode->left, word);

    return NULL;
}

void DestroyTree(Tree *treeNode) {
    if (!treeNode) return;

    free(treeNode->word);
    DestroyTree(treeNode->left);
    DestroyTree(treeNode->right);
    free(treeNode);
}

void PrintTree(Tree *treeNode) {
    printf("<");
    if (treeNode) {
        printf("%s ", treeNode->word);
        PrintTree(treeNode->left);
        PrintTree(treeNode->right);
    }
    printf(">");
}

int LeafsTree(Tree *treeNode) {
    if (!treeNode) return 0;

    int total = 0;
    if (treeNode->left == NULL && treeNode->right == NULL) 
        total += 1;

    total += LeafsTree(treeNode->left);
    total += LeafsTree(treeNode->right);

    return total;
}

static int max(int a, int b) {
    return a>b?a:b;
}

int HightTree(Tree *treeNode) {
    if (!treeNode) return 0;
    return 1 + max(HightTree(treeNode->left), HightTree(treeNode->right));
}
