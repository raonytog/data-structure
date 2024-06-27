#include "arv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Arv {
    Aluno *aluno;
    Arv *left, *right;
};

Aluno *busca_arvore(Arv *a, int id) {
    if (a == NULL) return NULL;
    else if (RetornaId(a->aluno) > id) busca_arvore(a->right, id);
    else if (RetornaId(a->aluno) < id) busca_arvore(a->left, id);
    else return a->aluno;
}

Arv *insere_aluno_arvore(Arv *a, Aluno *aluno) {
    /** Se nao node nenhum na arvore, cria um node com o aluno*/
    if (a == NULL) {
        a = malloc(sizeof(Arv));
        a->aluno = aluno;
        a->left = a->right = NULL;
    } 

    /** insere o aluno na esquerda ou direita, a depender do id dele ser 
     * maior ou menor do que o de seu node pai
     */
    else if (RetornaId(a->aluno) > RetornaId(aluno)) 
        a->left = insere_aluno_arvore(a->left, aluno);

    else 
        a->right = insere_aluno_arvore(a->right, aluno);

    return a;
}


Arv *retira_aluno_arvore(Arv *a, int id) {
    if (a == NULL) return NULL;

    /** Busca o node a ser removido */
    if (RetornaId(a->aluno) > id)
        a->left = retira_aluno_arvore(a->left, id);

    else if (RetornaId(a->aluno) < id)
        a->right = retira_aluno_arvore(a->right, id);

    /** remove o node */
    else {
        /** caso 1 (sem filhos) */
        if (a->left == NULL && a->right == NULL) {
            free(a);
            a = NULL;
        }

        /** caso 2 (1 filho) */
        // direita
        else if (a->left == NULL) {
            Arv *auxiliar = a;
            a = a->right;
            free(auxiliar);
        }

        // esquerda
        else if (a->right == NULL) {
            Arv *auxiliar = a;
            a = a->left;
            free(auxiliar);
        }

        /** caso 3 (2 filhos) */
        else {
            Arv *auxiliar = a->left;
            while (auxiliar->right != NULL) 
                auxiliar = auxiliar->right;

            Aluno *aluno = a->aluno;
            a->aluno = auxiliar->aluno;
            auxiliar->aluno = aluno;
            a->left = retira_aluno_arvore(a->left, id);
        }
    }

    return a;
}

void imprime_arvore(Arv *a) {
    printf("<");
    if (a) {
        ImprimeAluno(a->aluno);
        imprime_arvore(a->left);
        imprime_arvore(a->right);
    }
    printf(">");
}

int busca_binaria(Arv *a, int id) {
    if (!a) return -1;

    /** Verifica se eh o node com o aluno requisitado */
    if (RetornaId(a->aluno) == id) return 1;

    /** se o aluno ta a esquerda do avaliado*/
    else if (id < RetornaId(a->aluno))
        return busca_binaria(a->left, id);

    /** se o aluno ta a direita do avaliado */
    else if (id > RetornaId(a->aluno))
        return busca_binaria(a->right, id);
}

void libera_arvore(Arv *a) {
    if (!a) return;

    libera_arvore(a->left);
    libera_arvore(a->right);

    free(a);
}