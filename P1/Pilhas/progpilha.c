/*
*********************************
* Programa testador do TAD Pilha
*********************************
*/
#include <stdio.h>
#include "pilha.h"

int main() {
     // criando a pilha vazia
    Pilha* p = cria_pilha();

    // tentando imprimir a pilha (ainda vazia neste momento)
    imprime_pilha(p);
 
     // criando algumas pessoas apenas para testar (mais adequado seria carregar de um arquivo)
    Pessoa* pessoa1= inicializaPessoa("pessoa1", 51, "rua da pessoa1");
    Pessoa* pessoa2= inicializaPessoa("pessoa2", 63, "rua da pessoa2");
    Pessoa* pessoa3= inicializaPessoa("pessoa3", 10, "rua da pessoa3");
    Pessoa* pessoa4= inicializaPessoa("pessoa4", 70, "rua da pessoa4");
    Pessoa* pessoa5= inicializaPessoa("pessoa5", 20, "rua da pessoa5");
    Pessoa* pessoa6= inicializaPessoa("pessoa6", 30, "rua da pessoa6");
    Pessoa* pessoa7= inicializaPessoa("pessoa7", 40, "rua da pessoa7");
    Pessoa* pessoa8= inicializaPessoa("pessoa8", 45, "rua da pessoa8");
    Pessoa* pessoa9= inicializaPessoa("pessoa9", 65, "rua da pessoa9");
    Pessoa* pessoa10= inicializaPessoa("pessoa10", 67, "rua da pessoa10");
    Pessoa* pessoa11= inicializaPessoa("pessoa11", 13, "rua da pessoa11");

    //Insere os pessoas na pilha
    push(pessoa1, p); 
    push(pessoa2, p); 
    push(pessoa3, p); 
    push(pessoa4, p); 
    push(pessoa5, p); 
    push(pessoa6, p);
    push(pessoa7, p);
    push(pessoa8, p);
    push(pessoa9, p);
    push(pessoa10, p);
    push(pessoa11, p);

    printf ("---------- Imprime pilha-----------\n");
    //Imprime a pilha com todas as pessoas
    imprime_pilha(p);

    // Retira pessoa da pilha
    Pessoa* retirado = pop (p);

    imprime_pilha(p);

     //libera a mem�ria ocupada pela pilha
    p = destroi_pilha(p);
}