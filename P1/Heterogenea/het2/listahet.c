#include "listahet.h"

#define IMOVEL 0
#define MOVEL 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
    char *nome;
    int id;
};

struct movel {
    int placa, ano;
    float valor;
};

struct imovel {
    int id, ano;
    float valor;
};


/*Tipo que define a lista heterogenea(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD.  Use o ponteiro gen�rico para implementar a lista (void*)
  Campos da celula da lista: 
   - dono (Cliente*)
   - item (void*)
   - Prox (struct listahet*)
   - identificador do item (int)
*/
struct listahet {
    Cliente *dono;
    void *item;
    int identificador;
    ListaHet *next;
};

/*Cria lista vazia
* inputs: nenhum
* output: lista vazia
* pre-condicao: nenhuma
* pos-condicao: lista criada e vazia
*/
ListaHet* cria () {
    ListaHet *l = malloc(sizeof(ListaHet));
    l->identificador = -1;
    l->dono = NULL;
    l->item = NULL;
    l->next = NULL;
    return l;
}

/*Cria uma estrutura do tipo Cliente
* inputs: nome do cliente e o identificador do cliente
* output: Endere�o da estrutura cliente criada
* pre-condicao: nome e id validos
* pos-condicao: estrutura cliente criada, com os campos nome e id corretamente atribuidos
*/
Cliente* cria_cliente (char* nome, int id) {
    Cliente *c = malloc(sizeof(Cliente));
    c->id = id;
    c->nome = strdup(nome);
    return c;
}


/*Cria uma estrutura do tipo Movel
* inputs: placa, ano de fabricacao e valor do automovel 
* output: Endere�o da estrutura movel criada
* pre-condicao: placa, ano e valor validos
* pos-condicao: estrutura movel criada
*/
Movel* cria_movel (int placa, int ano, float valor) {
    Movel *m = malloc(sizeof(Movel));
    m->ano = ano;
    m->placa = placa;
    m->valor = valor;
    return m;
}

/*Cria uma estrutura do tipo Imovel
* inputs: identificador, ano de construcao e o valor do imovel
* output: Endere�o da estrutura imovel criada
* pre-condicao: id, ano e valor validos
* pos-condicao: estrutura imovel criada
*/
Imovel* cria_imovel (int id, int ano, float valor) {
    Imovel *i = malloc(sizeof(Imovel));
    i->ano = ano;
    i->id = id;
    i->valor = valor;
}

/*Insere um item (do tipo Movel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do automovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e automovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item) {
    if (!lista || !dono || !item) return NULL;

    if (!lista->dono) {
        lista->identificador = MOVEL;
        lista->dono = dono;
        lista->item = item;
        lista->next = NULL;
        return lista;
    }

    ListaHet *nova = cria();
    nova->dono = dono;
    nova->item = item;
    nova->identificador = MOVEL;
    nova->next = lista;
    return nova;
}


/*Insere um item (do tipo Imovel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do imovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e imovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item) {
    if (!lista || !dono || !item) return NULL;

    if (!lista->dono) {
        lista->identificador = IMOVEL;
        lista->dono = dono;
        lista->item = item;
        lista->next = NULL;
        return lista;
    }

    ListaHet *nova = cria();
    nova->dono = dono;
    nova->item = item;
    nova->identificador = IMOVEL;
    nova->next = lista;
    return nova;
}

/*Imprime os elementos da lista. Para cada elemento da lista, deve-se imprimir os dados do Cliente, seguido dos dados do im�vel (caso o item seja um im�vel) ou dos dados do autom�vel (caso o item seja um movel)
* inputs: a lista
* output: nao tem
* pre-condicao: lista valida
* pos-condicao: lista inalterada
*/
void imprime (ListaHet* lista) {
    if (!lista) return;

    ListaHet *auxiliar = lista;
    while (auxiliar) {
        printf("Dono: %s - ID: %d\n", auxiliar->dono->nome, auxiliar->dono->id);

        switch (auxiliar->identificador) {
            case IMOVEL:
                Imovel *imovel = auxiliar->item;
                printf("Ano: %d - ID: %d - R$%.2f\n\n", imovel->ano, imovel->id, imovel->valor);
                break;

            case MOVEL:
                Movel *movel = auxiliar->item;
                printf("Ano: %d - PLACA: %d - R$%.2f\n\n", movel->ano, movel->placa, movel->valor);
                break;
        }

        auxiliar = auxiliar->next;
    }
}

/*Retira da lista todos os itens assegurados de um dado cliente 
* inputs: a lista e o identificador do cliente
* output: lista atualizada
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista nao contem itens do cliente cujo identificador eh id_cliente
*/
ListaHet* retira_cliente (ListaHet* lista, int id_cliente) {
    if (!lista) return NULL;

    if (!lista->dono) return lista;

    ListaHet *auxiliar = lista, *ant = NULL, *temp = NULL;
    // se for o primeiro
    if (lista->dono->id == id_cliente) {
        auxiliar = lista->next;
        free(lista);

        // se for o unico
        if (!auxiliar) return NULL;
        else return auxiliar;
    }

    auxiliar = lista;
    while (auxiliar) {
        if (auxiliar->dono->id == id_cliente) {
            ant->next = auxiliar->next;
            temp = auxiliar;
            auxiliar = auxiliar->next;
            free(temp);

        } else {
            ant = auxiliar;
            auxiliar = auxiliar->next;
        }
    }
    return lista;
}

/*Calcula o valor total assegurado de um dado cliente (incluindo moveis e imoveis).
* Note que o valor assegurado depende da taxa estipulada para o tipo do item.
* O calculo do valor assegurado para UM dado item deve ser: valor_item*taxa_item
* inputs: a lista, o endereco do cliente, e as taxas para o calculo do valor assegurado. 
* output: valor total assegurado, que deve ser a soma dos valores assegurados de todos os itens do dado cliente
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista inalterada
*/
float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel) {
    if (!lista || !dono) return 0;

    float total = 0;
    ListaHet *auxiliar = lista;
    while (auxiliar) {
        if (auxiliar->dono == dono) {
            switch (auxiliar->identificador) {
                case MOVEL:
                    Movel *movel = auxiliar->item;
                    total += movel->valor * taxa_movel;
                    break;

                case IMOVEL:
                    Imovel *imovel = auxiliar->item;
                    total += imovel->valor * taxa_imovel;
                    break;
            }
        }

        auxiliar = auxiliar->next;
    }

    return total;
}