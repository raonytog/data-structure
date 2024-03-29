#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

#define ROWS1 2
#define COLS1 3

#define ROWS2 3
#define COLS2 2

int main () {
    int k = 0, i = 0, j = 0, opcao = 0;
    Matriz * m1 = inicializaMatriz(ROWS1, COLS1);   k = 0;
    for (i = 0; i < ROWS1; i++) {
        for (j = 0; j < COLS1; j++) {
            modificaElemento(m1, i, j, k++);
        }
    }
    printf("A matriz A:\n");
    imprimeMatriz(m1);

    Matriz * m2 = inicializaMatriz(ROWS2, COLS2);   k = 100;
    for (i = 0; i < ROWS2; i++) {
        for (j = 0; j < COLS2; j++) {
            modificaElemento(m2, i, j, k++);
        }
    }
    printf("A matriz B:\n");
    imprimeMatriz(m2);

    printf("A matriz AB:\n");
    Matriz * mult = multiplicacao(m1, m2);
    imprimeMatriz(mult);


    printf("A matriz transposta de A:\n");
    Matriz * transp = transposta(m1);
    imprimeMatriz(transp);

    destroiMatriz(m1);
    destroiMatriz(m2);
    destroiMatriz(mult);
    destroiMatriz(transp);

    return 0;
}