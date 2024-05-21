#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct pessoa {
    char *nome, *endereco;
    int idade;
};


/*Tipo que define a Pilha (tipo opaco)
  Atencao: Esta pilha pode conter ate 10 Pessoas
*/
struct pilha {
    Pessoa *pessoas[MAX];
    int base, topo;
};


/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P est� definida e vazia
*/
Pilha* cria_pilha() {
    Pilha *stack = malloc(sizeof(Pilha));
    stack->topo = -1;
    stack->base = 0;
    return stack;
}

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da fun��o, a pilha tem E como o elemento
do topo
*/
void push(Pessoa* pessoa, Pilha* pilha) {
    if (!pessoa || !pilha) return;

    if (tamanho_pilha(pilha) == MAX-1) {
        printf("A pilha esta cheia!\n");
        free(pessoa->endereco);
        free(pessoa->nome);
        free(pessoa);
        return;
    }

    pilha->topo++;
    pilha->pessoas[pilha->topo] = pessoa;
}


/*Retira uma Pessoa do topo da Pilha (se pilha n�o vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha n�o � nula e n�o � vazia
* pos-condicao: pilha n�o cont�m o elemento retirado do topo
*/
Pessoa* pop(Pilha* pilha) {
    if (!pilha) return NULL;

    if (vazia_pilha(pilha)) return NULL;

    Pessoa *ans = pilha->pessoas[pilha->topo];
    free(ans->endereco);
    free(ans->nome);
    free(ans);
    
    pilha->pessoas[pilha->topo] = NULL;
    pilha->topo--;
    return ans;
}


/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha n�o � nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha* destroi_pilha(Pilha* pilha) {
    if (!pilha) return NULL;

    for (int i = 0; i < pilha->topo+1; i++) {
        free(pilha->pessoas[i]->endereco);
        free(pilha->pessoas[i]->nome);
        free(pilha->pessoas[i]);
    }

    free(pilha);
    return NULL;
}

/*Verifica se a pilha estah vazia
* inputs: a Pilha
* output: 1 (se vazia), 0 (caso contrario)
* pre-condicao: Pilha n�o � nula
* pos-condicao: Pilha permanece inalterada
*/
int vazia_pilha (Pilha* pilha) {
    if (!pilha) return -1;
    if (pilha->topo == -1) return 1;
    return 0;
}


/*Retorna o numero de elementos da pilha
* inputs: a Pilha
* output: o numero de elementos da pilha
* pre-condicao: Pilha n�o � nula
* pos-condicao: Pilha permanece inalterada
*/
int tamanho_pilha (Pilha* pilha) {
    if (!pilha) return -1;
    return pilha->topo;
}

/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco) {
    if (!nome || !endereco || idade < 0) return NULL;

    Pessoa *p = malloc(sizeof(Pessoa));
    p->endereco = strdup(endereco);
    p->nome = strdup(nome);
    p->idade = idade;
    return p;
}


/*Imprime as pessoas da pilha
* inputs: a pilha
* output: nenhum
* pre-condicao: pilha P n�o vazia
* pos-condicao: Pilha permanece inalterada
*/
void imprime_pilha (Pilha* pilha) {
    if (!pilha) return;

    for (int i = 0; i < pilha->topo+1; i++) {
        imprimepessoa(pilha->pessoas[i]);
    }
    printf("\n");
}


/*Imprime os dados de uma pessoa
* inputs: Uma estrutura pessoa
* output: nenhum
* pre-condicao: Pessoa P n�o nula
* pos-condicao: Os dados da pessoa permanecem inalterados
*/
void imprimepessoa(Pessoa* p) {
    if (!p) return;
    printf("\tNome: %s, Idade: %d, Endereco: %s\n", p->nome, p->idade, p->endereco);
}


/*Retorna a idade de uma pessoa
* inputs: Uma estrutura pessoa
* output: nenhum
* pre-condicao: Pessoa P n�o nula
* pos-condicao: Os dados da pessoa permanecem inalterados
*/
int retorna_idade (Pessoa* p) {
    if (!p) return -1;
    return p->idade;
}