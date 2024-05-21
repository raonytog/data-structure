/*
*********************************
* Programa testador do TAD Fila (usando pilhas)
* *********************************
*/
#include <stdio.h>
#include "fila.h"

int main() {
    // criando a fila vazia
    Fila* f = cria_fila();

    //Insere os pessoas na fila
    insere(10, f);
    insere(20, f); 
    insere(30, f); 
    insere(40, f); 
    insere(50, f); 
    insere(60, f);
    insere(70, f);
    insere(80, f);
    insere(90, f);
    insere(100, f);
    insere(110, f);
    imprime_fila(f);

    int retirado = retira (f);
    insere (retirado, f);
    imprime_fila(f);

    
    Fila* f_maiores = cria_fila(); 
    Fila* f_menores = cria_fila(); 

    separa_filas(f, f_maiores, f_menores);

    imprime_fila(f);

    printf("\tMAIORES------------\n");
    imprime_fila(f_maiores);

    printf("\tMENORES------------\n");
    imprime_fila(f_menores);

    //libera a mem�ria ocupada pela fila 
    f = destroi_fila(f);
    f_maiores = destroi_fila(f_maiores);
    f_menores = destroi_fila(f_menores);
}