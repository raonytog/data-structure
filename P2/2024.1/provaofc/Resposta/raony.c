#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pais.h"
#include "tadhash.h"

/**
 * Raony Togneri Gomes
*/

static void PrintVector(Pais **vector, int size){
    if (!vector || size < 0) return;

    for(int i = 0; i < size; i++)
        PrintPais(vector[i]);
}

int main () {
    /** 
     * ------------ Parte 1 ------------ 
     */
    FILE *fEntrada = fopen("entrada.txt", "r");
    if (!fEntrada) {
        printf("Arquivo nao abriu!");
        return EXIT_FAILURE;
    }

    char nomePais[4]; 
    int ouro = 0, prata = 0, bronze = 0, total = 0;

    /** Insere na hash o que foi lido nos arquivos */
    Hash *ht = InitHash();
    while (fscanf(fEntrada, "%s %d %d %d %d", nomePais, &ouro, &prata, &bronze, &total) == 5) {
        Pais *buscado = SearchHash(ht, nomePais);
        if (buscado != NULL) {
            AtualizaInformacoesPais(buscado, ouro, prata, bronze, total);

        } else {
            Pais *paisTemporario = InitPais(nomePais, ouro, prata, bronze, total);
            InsertHash(ht, paisTemporario);
        }
    }
    fclose(fEntrada);
   
    /** 
     * ------------ Parte 2 ------------ 
     */
    FILE *fSaida = fopen("saida.txt", "w");
    if (!fSaida) {
        printf("Nao abriu arquivo de saida");
        return EXIT_FAILURE;
    }


    /** Ordena e imprime no arquivo*/
    Pais **vector = calloc(getHashSize(ht), sizeof(Pais*));
    for(int i = 0; i < getHashSize(ht); i++) {
        vector[i] = malloc(sizeof(Pais*));
    }

    FillVector(ht, vector);
    SortPaises(vector, getHashSize(ht), fSaida);
    fclose(fSaida);
    

    /** Libera a memoria do programa*/
    int size = getHashSize(ht);
    DestroyHash(ht);
    
     /** 
     * Comentei este trecho pois ele dava double free no codigo
     * mas o numero de free que falta no codigo vem daqui. Gastei
     * cerca de 40min tentando entender o que fazer para resovler
     * esse erro de double free, mas nao consegui :(
     */

    // for (int i = 0; i < size; i++) {
    //     if (vector[i]) free(vector[i]);
    //     vector[i] = NULL;
    // }
    free(vector);
    return 0;
}