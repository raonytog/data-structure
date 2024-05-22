#include "BanhoTosa.h"
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */
struct BanhoTosa {
    char *nome;
    Lista *agressivos, *mansos;
};

/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome) {
    BanhoTosa *b = malloc(sizeof(BanhoTosa));
    b->nome = strdup(nome);
    b->mansos = CriaLista();
    b->agressivos = CriaLista();
    return b;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog) {
    if (!loja || !dog) return;
    switch (getNivelAgressividadeCachorro(dog)) {
        case BRAVO:
            InsereLista(loja->agressivos, dog, CACHORRO);
            break;
    
        case MANSO:
            InsereLista(loja->mansos, dog, CACHORRO);
            break;
    }
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat) {
    if (!loja || !cat) return;
    switch (getNivelAgressividadeGato(cat)) {
        case BRAVO:
            InsereLista(loja->agressivos, cat, GATO);
            break;
    
        case MANSO:
            InsereLista(loja->mansos, cat, GATO);
            break;
    }
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat) {
    if (!loja || !cat) return;

    switch (getNivelAgressividadeGato(cat)) {
        case BRAVO:
            RetiraLista(loja->mansos, cat);
            InsereLista(loja->agressivos, cat, GATO);
            break;

        case MANSO:
            RetiraLista(loja->agressivos, cat);
            InsereLista(loja->mansos, cat, GATO);
            break;
    }
}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog) {
    if (!loja || !dog) return;

    switch (getNivelAgressividadeCachorro(dog)) {
        case BRAVO:
            RetiraLista(loja->mansos, dog);
            InsereLista(loja->agressivos, dog, CACHORRO);
            break;

        case MANSO:
            RetiraLista(loja->agressivos, dog);
            InsereLista(loja->mansos, dog, CACHORRO);
            break;
    }
}


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja) {
    if (!loja) return;
    printf("\n---=== Banho e Tosa da Patricia ===-\n");
    
    if (loja->mansos) {
        printf("Os animais mansos:\n");
        ImprimeLista(loja->mansos);
        printf("\n"); }

    if (loja->agressivos) {
        printf("Os animais bravos:\n");
        ImprimeLista(loja->agressivos);
        printf("\n"); }

    printf("---=== ------------------------ ===-\n");
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja) {
    float receitaGatosBravos = RetornaQtdGatos(loja->agressivos) * 35;
    float receitaGatosMansos = RetornaQtdGatos(loja->mansos) * 30;

    float receitaCachorrosBravos = RetornaQtdCachorros(loja->agressivos) * 45;
    float receitaCachorrosMansos = RetornaQtdCachorros(loja->mansos) * 40;


    return receitaGatosBravos + receitaGatosMansos + 
           receitaCachorrosBravos + receitaCachorrosMansos;
}


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja) {
    if (!loja) return;

    free(loja->nome);
    LiberaLista(loja->agressivos);
    LiberaLista(loja->mansos);
    free(loja);
}