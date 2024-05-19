#include "pedido.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula Celula;

struct Celula {
    TProduto *produto;
    Celula *next;
};

struct pedido {
    char *donoPedido;
    Celula *first, *last;
};

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono) {
    if (!dono) return NULL;
    TPedido *p = malloc(sizeof(TPedido));
    p->donoPedido = strdup(dono);
    p->first = p->last = NULL;

    return p;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod) {
    if (!pedido || !prod) return;

    Celula *auxiliar = pedido->first;
    while (auxiliar) {
        if (strcmp(RetornaNome(auxiliar->produto), RetornaNome(prod)) == 0) {
            printf("Produto já existe no pedido\n");
            return;
        }
        auxiliar = auxiliar->next;
    }

    Celula *produto = malloc(sizeof(Celula));
    produto->produto = prod;
    produto->next = NULL;

    // lista vazia
    if (!pedido->first && !pedido->last) {
        pedido->first = pedido->last = produto;
        return;
    }

    pedido->last->next = produto;
    pedido->last = produto;
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido) {
    if (!pedido) return;
    printf("\nDono do pedido: %s\n", pedido->donoPedido);
    for (Celula *i = pedido->first; i; i = i->next) {
        ImprimeIngredientes(i->produto);
    }
}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod) {
    if (!pedido || !prod) return;

    // lista vazia
    if (!pedido->first && !pedido->last) return;


    Celula *auxiliar = pedido->first, *anterior = NULL;
    // se for o primeiro
    if (strcmp(RetornaNome(auxiliar->produto), prod) == 0) {
        pedido->first = pedido->first->next;
        free(auxiliar);

        // se for unico
        if (!pedido->last) {
            pedido->last = NULL;
        }
    }

    // demais
    for (auxiliar = pedido->first; auxiliar; auxiliar = auxiliar->next) {
        if (strcmp(RetornaNome(auxiliar->produto), prod) == 0) {
            anterior->next = auxiliar->next;
            free(auxiliar);
            return;
        }

        anterior = auxiliar;
    }
}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: nPedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar) {
    if (!pedido) return -1;

    int totalCal = 0;
    Celula *auxiliar = pedido->first;
    for (; auxiliar; auxiliar = auxiliar->next) {
        // verifica se ha restricao alimentar
        if (VerificaIngrediente(auxiliar->produto, restricao_alimentar) == 1) {
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", restricao_alimentar);
            return 0;
        }

        totalCal += Calorias(auxiliar->produto);
        if (totalCal > restricao_calorica) {
            printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
            return 0;
        }
    }

    auxiliar = pedido->first;
    free(pedido->donoPedido);
    while (auxiliar) {
        auxiliar = auxiliar->next;
        free(pedido->first);
        pedido->first = auxiliar;
    }
    free(pedido);
    return 1;
}