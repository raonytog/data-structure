#include "posto.h"
#include "fila.h"

//Define o limite entre positivo e negativo
//Amostras com carga viral >= LIMETE_CARGA_VIRAL são consideradas POSITIVAS
//Amostras com carga viral < LIMETE_CARGA_VIRAL são consideradas NEGATIVAS
#define LIMITE_CARGA_VIRAL 500

/*Tipo que define um Posto de Saúde (tipo opaco)
 *Um posto deve ter os seguintes atributos:
 * * Nome do Posto
 * * Uma FILA de amostras para exame não processadas
 * * Uma FILA de amostras processadas com resultado POSITIVO
 * * Uma FILA de amostras processadas com resultado NEGATIVO
 * */
struct posto {
    char *nome;
    Fila *examesNaoProcessados, *examesNegativos, *examesPositivos;
};

Posto* inicPosto(char* nome) {
    Posto *posto = malloc(sizeof(Posto));
    posto->nome = strdup(nome);

    posto->examesNaoProcessados = IniciaFila();
    posto->examesNegativos = IniciaFila();
    posto->examesPositivos = IniciaFila();

    return posto;
}

void imprimePosto(Posto* posto) {
    if (!posto) return;

    printf("Dados do posto: %s\n", posto->nome);
    printf("Amostras nao processadas\n");
    ImprimeFila(posto->examesNaoProcessados);

    printf("\nAmostras com resultados positivos\n");
    ImprimeFila(posto->examesPositivos);

    printf("\nAmostras com resultados negativos\n");
    ImprimeFila(posto->examesNegativos);
    printf("\n\n\n");
}

void realizaColeta(Posto* posto, char* pessoa, int idade) {
    if (!posto || !pessoa || !idade) return;

    Amostra *amostra = inicAmostra(pessoa, idade);
    if (idade >= 60) InsereFilaInicio(posto->examesNaoProcessados, amostra);
    else InsereFilaFinal(posto->examesNaoProcessados, amostra);
}

void processaLoteAmostras(Posto* posto) {
    if (!posto) return;

    Amostra *amostra;
    while (!EstaVaziaLista(posto->examesNaoProcessados)) {
        amostra = RetiraFila(posto->examesNaoProcessados);

        if (retornaCargaViral(amostra) >= LIMITE_CARGA_VIRAL) {
            registraResultado(amostra, POSITIVO);
            if (retornaIdade(amostra) >= 60) InsereFilaInicio(posto->examesPositivos, amostra);
            else InsereFilaFinal(posto->examesPositivos, amostra);

        } else if (retornaCargaViral(amostra) < LIMITE_CARGA_VIRAL) {
            registraResultado(amostra, NEGATIVO);
            if (retornaIdade(amostra) >= 60) InsereFilaInicio(posto->examesNegativos, amostra);
            else InsereFilaFinal(posto->examesNegativos, amostra);
        }
    }
}

void liberaPosto(Posto* posto) {
    if (!posto) return;

    free(posto->nome);
    Liberafila(posto->examesNaoProcessados);
    Liberafila(posto->examesNegativos);
    Liberafila(posto->examesPositivos);

    free(posto);
}

