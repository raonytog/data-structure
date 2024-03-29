//
//  matriz.h
//  TADMatriz
//
//  Created by Patricia Dockhorn Costa on 19/09/20.
//  Copyright © 2020 Patricia Dockhorn Costa. All rights reserved.
//

#include "matriz.h"
#include <stdlib.h>

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementaÁ„o do TAD
struct matriz {
    int nRows, nCols, *grid;
    // Para percorrer o vetor, usar v[k], sendo k = i*n + j, onde n = nCols da matriz
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas) {
    if (nlinhas <= 0 || ncolunas <= 0) return NULL;

    Matriz * m = malloc(sizeof(Matriz));
    if (!m) {
        printf("Alocacao errada da matriz!\n"); 
        exit(1);
    }

    m->grid = calloc(nlinhas * ncolunas, sizeof(int));
    if (!m->grid) {
        printf("Alocacao errada no grid!\n");
        exit(1);
    }

    m->nCols = ncolunas;            m->nRows = nlinhas;
    return m;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem) {
    if (!mat) return;
    if (linha < 0 || coluna < 0 || 
        linha >= recuperaNLinhas(mat) || 
        coluna >= recuperaNColunas(mat)) {
        printf("A linha e/ou a coluna nao eh valida");
        exit(1);
    }
    mat->grid[linha * mat->nCols + coluna] = elem;  
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: mat n„o È modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna) {
    if (!mat) return 0;
    if (linha < 0 || coluna < 0 || 
        linha >= recuperaNLinhas(mat) || 
        coluna >= recuperaNColunas(mat)) {
        printf("A linha e/ou a coluna nao eh valida");
        exit(1);
    }
    return mat->grid[linha * mat->nCols + coluna];
}

/*Retorna o n˙mero de colunas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNColunas (Matriz* mat) {
    if (!mat) return 0;
    return mat->nCols;
    }

/*Retorna o n˙mero de linhas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNLinhas (Matriz* mat) {
    if (!mat) return 0;
    return mat->nRows;
    }

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat) {
    if (!mat) return NULL;
    Matriz * ans = inicializaMatriz(recuperaNColunas(mat), recuperaNLinhas(mat));
    for (int i = 0; i < recuperaNLinhas(ans); i++) {
        for (int j = 0; j < recuperaNColunas(ans); j++) {
            ans->grid[i*recuperaNColunas(ans) + j] = mat->grid[j*recuperaNColunas(mat) + i];
        }
    }
    
    return ans;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicaÁ„o
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 n„o s„o modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2) {
    if (!mat1 || !mat2) return NULL;
    if (mat1->nCols != mat2->nRows) {
        printf("Nao eh possivel multiplicar as matrizes!\n");
        return NULL;
    };

    Matriz * ans = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));

    for(int m = 0; m < recuperaNLinhas(mat1); m++) {
        for (int r = 0; r < recuperaNColunas(mat2); r++) {
            for(int n = 0; n < recuperaNColunas(mat1); n++) {
                ans->grid[m*recuperaNColunas(ans) + r] += mat1->grid[m*recuperaNColunas(mat1) + n] * mat2->grid[n*recuperaNColunas(mat2) + r];
            }
        }
    }

    return ans;
}

/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat) {
    if (!mat) return;
    for (int i = 0; i < recuperaNLinhas(mat); i++) 
        imprimeLinhas(mat, i);
    printf("\n");
}

void imprimeLinhas (Matriz* mat, int indice) {
    if (!mat) return;
    for (int j = 0 ; j < mat->nCols; j++) {
        printf("%d ", mat->grid[indice*mat->nCols + j]);
    }
    printf("\n");
}

void destroiMatriz (Matriz* mat) {
    if (!mat) return;
    free(mat->grid);
    free(mat);
}