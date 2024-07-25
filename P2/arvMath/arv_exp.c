
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "arv_exp.h"

struct arv {
    char operador;
    int operando;
    Arv *left, *right;
};

/*Cria uma arvore vazia, ou seja, retorna NULL
* inputs: nenhum
* output: NULL
*/
Arv* CriaVazia(void) {
    return NULL;
}

/*cria um nó raiz de operador dados o operador e as duas sub-árvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endereço do nó raiz criado
*/
Arv* CriaOperador(char c, Arv* esq, Arv* dir) {
    if (!c) return NULL;

    Arv *new = malloc(sizeof(Arv));
    new->operador = c;
    new->left = esq;
    new->right = dir;

    return new;
}

/*cria um nó operando dado o valor do no (como o operando é um nó folha, as sub-arvores da esquerda e da direita são nulas
* inputs: o operando
* output: o endereço do nó raiz criado
*/
Arv* CriaOperando(int valor) {
    Arv *new = malloc(sizeof(Arv));
    new->left = new->right= NULL;
    new->operando = valor;

    return new;
}

/*Imprime a árvore em notação InOrder (esq, raiz, direita)
* inputs: o endereço da raiz da árvore
* output: nenhum
*/
void Imprime(Arv* arv) {
    printf("<");
    if (arv) {
        if (arv->left == NULL && arv->right == NULL) printf("%d ", arv->operando);
        else printf("%c ", arv->operador); 

        Imprime(arv->left);
        Imprime(arv->right);
    }
    printf(">");
}

/* Libera memória alocada pela estrutura da árvore
as sub-árvores devem ser liberadas antes de se liberar o nó raiz
* inputs: o endereço da raiz da árvore
* output: uma árvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv) {
    if (!arv) return NULL;

    Libera(arv->left);
    Libera(arv->right);
    free(arv);

    return NULL;
}


/* Retorna o valor correspondente à avaliação da expressão representada na árvore
* inputs: o endereço da raiz da árvore
* output: o valor da expressão
*/
float Avalia(Arv* arv) {
    if (!arv) return 0;

    /** pega o numero */
    if (arv->left == NULL && arv->right == NULL) 
        return arv->operando;

    /** armazena aqui o numero */
    float left = Avalia(arv->left),
          right = Avalia(arv->right);

    switch (arv->operador) {
        case '+':
            return left+right;

        case '-':
            return left-right;

        case '*':
            return left*right;

        case '/':
            return left/right;
    }
}


/* Retorna o número de folhas da árvore
* inputs: o endereço da raiz da árvore
* output: o número de folhas
*/
int Folhas(Arv* arv) {
    if (!arv) return 0;
    int total = 0;

    if (arv->left == NULL && arv->right == NULL) 
        total++;

    total += Folhas(arv->left);
    total += Folhas(arv->right);

    return total;
}

static int max(int a, int b) {
    return (a>b)?a:b;
}

/* Retorna a altura da árvore
* inputs: o endereço da raiz da árvore
* output: a altura da árvore
*/
int Altura(Arv* arv) {
    if (!arv) return 0;
    return 1 + max(Altura(arv->left), Altura(arv->right));
}

