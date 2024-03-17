#include <stdio.h>
#include <stdlib.h>

int** inverte2 (int n, int* vet);

int main () {
    // tamanho do vetor
    int n = 5;

    // alocando e preenchendo o vetor
    int *vet = malloc(n * sizeof(int));
    int aux = 1;
    for (int i = 0; i < n; i++) {
        vet[i] = aux++;
    }

    // cria uma matriz N x 2 e imprime
    int ** matriz = inverte2(n, vet);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // desaloca o ** e o vet
    free(vet);
    for (int i = 0; i < 2; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

/**
 * Retorna uma nova matriz, com o vetor inicial e outro vetor com o 
 * endereco de cada posicao do vetor, de forma ordenada crescente
*/
int** inverte2 (int n, int* vet) {
    // aloca a matriz resposta
    int ** ans = malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++) {
        ans[i] = malloc(n * sizeof(int));
    }

    // copia os valores para a matrix
    for (int i = 0; i < n; i++) {
        ans[0][i] = vet[i];
        ans[1][i] = &vet[i];
    }

    // ordena os enderecos de memoria
    int temp = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n-1; j++) {
            if (ans[1][i] > ans[1][j]) {
                temp = ans[1][i];
                ans[1][i] = ans[1][j];
                ans[1][j] = temp;
            }
        }   
    }

    return ans;
}