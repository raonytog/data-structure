#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "pessoa.h"

#define MAX 100

int main() { 
    Hash *htable = InitHash(MAX);

    FILE* fEntrada = fopen("entrada.txt", "r"); 
    if (fEntrada == NULL) { printf("no such file."); return 0; } 
    
    int qtdAulas = 0; char nome[100], presenca; 
    fscanf(fEntrada, "%*c %d", &qtdAulas);
    while (fscanf(fEntrada, "%s", nome) == 1) {
        Pessoa *newPerson = InitPessoa(nome);
        htable = InsertHash(htable, newPerson);
    }
    fclose(fEntrada);

    char endereco[100];
    for (int i = 0; i < qtdAulas; i++) {
        sprintf(endereco, "entrada%d.txt", i+1);
        FILE *fEndereco = fopen(endereco, "r");

        char presenca = '\0';
        while (fscanf(fEndereco, "%s %c", nome, &presenca) == 2) {
            HashSearch(htable, nome, presenca);
        }
        fclose(fEndereco);
    }
    PrintHash(htable);
    DestroyHash(htable);
  
    return 0;
}