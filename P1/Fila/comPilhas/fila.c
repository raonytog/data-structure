#include "fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct fila {
    Pilha *p1, *p2;
};

Fila* cria_fila(void) {
    Fila *f = malloc(sizeof(Fila));
    f->p1 = cria_pilha();
    f->p2 = cria_pilha();
    return f;
}

void insere (Pessoa* pessoa, Fila* f) {
    if (!perror || !f) return;

    push(pessoa, f->p1);
}

/*Retira uma pessoa da fila (usando FIFO). Imprime mensagem de erro caso a fila esteja vazia.
* inputs: a fila
* output: a Pessoa (do tipo Pessoa) retirada da Fila (ou NULL, caso a fila esteja vazia)
* pre-condicao: fila n�o � nula
* pos-condicao: fila n�o cont�m a pessoa que estava na primeira posicao */
Pessoa* retira (Fila* f) {
    if (!f) return NULL;

    while (!vazia_pilha(f->p1)) {
        Pessoa *pessoa = pop(f->p1);
        push(pessoa, f->p2);
    }

    /** pessoa no topo da pilha sera a pessoa no primeiro lugar da fila, entao
     * iremos exclui-la;
    */
    Pessoa *excluida = pop(f->p2);
    while (!vazia_pilha(f->p2)) {
        Pessoa *pessoa = pop(f->p2);
        push(pessoa, f->p1);
    }
    return excluida;
}


/*Imprime os dados de todos as pessoas da fila (do inicio ao fim da fila!). Imprime mensagem de fila vazia, caso a fila esteja vazia.
* inputs: a fila de pessoas
* output: nenhum
* pre-condicao: fila n�o � nula
* pos-condicao: dados dos pessoas impressos na saida padrao
*/
void imprime_fila (Fila* f) {
    if (!f) return;
    imprime_pilha(f->p1);
}


/*Verifica se a fila esta ou nao vazia
* inputs: a fila de pessoas
* output: 1 se estiver vazia e zero caso contrario
* pre-condicao: fila n�o � nula
* pos-condicao: nenhuma
*/
int Vazia_fila (Fila* f) {
    if (!f) return -1;
    if (vazia_pilha(f->p1)) return 1;
    return 0;
}


/*Separa a fila f de tal forma que as pessoas com idade maior que 60 sejam movidas para a fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores".
* inputs: a fila de pessoas, as filas f_maiores e f_menores (inicialmente vazias)
* output: nao tem
* pre-condicao: fila f n�o � nula
* pos-condicao: fila f vazia, pessoas com idade maior ou igual a 60 na fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores" */
void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores) {
    if (!f) return;

    while (!Vazia_fila(f)) {
        Pessoa *pessoa = pop(f->p1);
        if (retorna_idade(pessoa) >= 60) push(pessoa, f_maiores->p1);
        else push(pessoa, f_menores->p1);
    }
}


/*Libera toda a mem�ria utilizada pelas estruturas de dados.
* inputs: a fila de pessoas
* output: NULL
* pre-condicao: fila f n�o � nula
* pos-condicao: Mem�ria liberada */
Fila* destroi_fila (Fila* f) {
    if (!f) return NULL;

    f->p1 = destroi_pilha(f->p1);
    f->p2 = destroi_pilha(f->p2);
    free(f);
    return f;
}