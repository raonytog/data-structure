#include "BanhoTosa.h"
#include "lista.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct BanhoTosa {
    char  *nome;
    Lista *bravos;
    Lista *mansos;
};

/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome) {
    BanhoTosa *b = malloc(sizeof(BanhoTosa));
    b->nome = strdup(nome);
    b->mansos = IniciaLista();
    b->bravos = IniciaLista();
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
                InsereNaLista(loja->bravos, dog, CACHORRO);
            break;
        
        case MANSO:
                InsereNaLista(loja->mansos, dog, CACHORRO);
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
                InsereNaLista(loja->bravos, cat, GATO);
            break;
        
        case MANSO:
                InsereNaLista(loja->mansos, cat, GATO);
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
            RetiraDaLista(loja->mansos, cat);
            InsereNaLista(loja->bravos, cat, GATO);
            break;

        case MANSO:
            RetiraDaLista(loja->bravos, cat);
            InsereNaLista(loja->mansos, cat, GATO);
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
            RetiraDaLista(loja->mansos, dog);
            InsereNaLista(loja->bravos, dog, CACHORRO);
            break;

        case MANSO:
            RetiraDaLista(loja->bravos, dog);
            InsereNaLista(loja->mansos, dog, CACHORRO);
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

    if (loja->bravos) {
        printf("Os animais bravos:\n");
        ImprimeLista(loja->bravos);
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
    float receitaGatosBravos = RetornaQtdGatos(loja->bravos) * 35;
    float receitaGatosMansos = RetornaQtdGatos(loja->mansos) * 30;

    float receitaCachorrosBravos = RetornaQtdCachorros(loja->bravos) * 45;
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
    LiberaLista(loja->bravos);
    free(loja->bravos);

    LiberaLista(loja->mansos);
    free(loja->mansos);
    
    free(loja);
}
