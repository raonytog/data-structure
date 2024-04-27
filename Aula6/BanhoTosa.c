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

BanhoTosa* inicBanhoTosa(char* nome) {
    BanhoTosa *b = malloc(sizeof(BanhoTosa));
    b->nome = strdup(nome);
    b->mansos = IniciaLista();
    b->bravos = IniciaLista();
    return b;
}

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

float calculaReceita(BanhoTosa* loja) {
    float receitaGatosBravos = RetornaQtdGatos(loja->bravos) * 35;
    float receitaGatosMansos = RetornaQtdGatos(loja->mansos) * 30;

    float receitaCachorrosBravos = RetornaQtdCachorros(loja->bravos) * 45;
    float receitaCachorrosMansos = RetornaQtdCachorros(loja->mansos) * 40;


    return receitaGatosBravos + receitaGatosMansos + 
           receitaCachorrosBravos + receitaCachorrosMansos;
}

void liberaBanhoTosa(BanhoTosa* loja) {
    if (!loja) return;
    free(loja->nome);

    LiberaLista(loja->bravos);
    //free(loja->bravos);

    LiberaLista(loja->mansos);
    //free(loja->mansos);
    
    free(loja);
}
