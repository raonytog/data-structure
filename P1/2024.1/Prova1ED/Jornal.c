#include "Jornal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Raony Togneri Gomes, 22 de maio de 2024
*/

typedef struct Celula Celula;

struct Celula {
    time_t horaPublicada;
    Celula *next;
    Noticia *noticia;
};

//Define a estrutura do jornal... parte da prova pensar no que é necessário
struct jornal {
    int numNoticias;
    char *nome;
    Celula *first, *last;
};

//Cria um tipo Jornal, dado o nome do jornal
//pré-condição: nome é uma string válida
//pós-condição: Estrutura Jornal alocada e considerada "vazia"
Jornal* criaJornal(char* nome) {
    Jornal *j = malloc(sizeof(Jornal));
    j->nome = strdup(nome);
    j->numNoticias = 0;
    j->first = j->last = NULL;
    return j;
}

//Insere notícia "news" no jornal "j"
//A notícia já tem um timestamp de criação. Deve alocar também um timestamp de publicação
//Caso o intervalo entre tempo de criação e publicação seja <=TEMPO_PREMIACAO
//O autor deve ser premiado
void insereNoticia(Jornal* j, Noticia* news) {
    if (!j || !news) return;

    Celula *nova = malloc(sizeof(Celula));
    nova->noticia = news;
    nova->horaPublicada = time(NULL);
    nova->next = NULL;


    if ((nova->horaPublicada - retornaHora(news)) <= TEMPO_PREMIACAO)
        premiaAutor(retornaAutor(news));

    if (!j->first && !j->last) {
        j->first = j->last = nova;
        j->numNoticias++;
        return;
    }

    j->last->next = nova;
    j->last = nova;
    j->numNoticias++;
}

//Remove as notícias "velhas" do jornal j
//Se ("agora" - tempo de publicação) for >=TEMPO_NOTICIA_VELHA, a notícia é considerada "velha"
//ATENÇÃO: Deve-se liberar a memória das notícias removidas do jornal
void removeNoticiasVelhas(Jornal* j) {
    if (!j) return;

    Celula *auxiliar = j->first, *ant, *temp;
    if (time(NULL) - retornaHora(j->first->noticia) >= TEMPO_NOTICIA_VELHA) {
        j->numNoticias--;
        if (j->numNoticias == 0) {
            liberaNoticia(j->first->noticia);
            free(j->first);
            j->first = j->last = NULL;
            return;
        }

        temp = j->first->next;
        liberaNoticia(j->first->noticia);
        free(j->first);
        j->first = temp;
        return;
    }


    while (auxiliar) {
        if ((time(NULL) - retornaHora(auxiliar->noticia)) >= TEMPO_NOTICIA_VELHA) {
            j->numNoticias--;
            ant->next = auxiliar->next;
            liberaNoticia(auxiliar->noticia);
            free(auxiliar);
            return;

        }

        ant = auxiliar;
        auxiliar = auxiliar->next;
    }
}

//Imprime as notícias do jornal no seguinte formato
/*Notícias do Jornal Jornal da UFES

***** Notícia: UFES recomenda uso de mascaras
***** Hora de Acontecimento: Sun Nov 20 19:45:36 2022
***** Autor da Noticia: Luis
***** Hora de Publicação: Sun Nov 20 19:45:46 2022

***** Notícia: Assalto na UFES assusta comunidade acadêmica
***** Hora de Acontecimento: Sun Nov 20 19:45:36 2022
***** Autor da Noticia: Edu
***** Hora de Publicação: Sun Nov 20 19:45:36 2022

***** Notícia: Curso da UFES é premiado no ENADE
***** Hora de Acontecimento: Sun Nov 20 19:45:36 2022
***** Autor da Noticia: Patricia
***** Hora de Publicação: Sun Nov 20 19:45:36 2022 */
void imprimeNoticiasJornal(Jornal* j) {
    if (!j) return;

    Celula *auxiliar = j->first;
    printf("Noticias do jornal %s\n", j->nome);

    while (auxiliar){
        imprimeNoticia(auxiliar->noticia);
        printf("\n***** Hora de Publicação: %s", ctime(&auxiliar->horaPublicada));
        auxiliar = auxiliar->next;
    }
}

//Imprime as notícias como especificado acima, porém, somente de autores premiados
void imprimeNoticiasAutoresPremiados(Jornal* j) {
    if (!j) return;

    Celula *auxiliar = j->first;
    while (auxiliar) {
        if (ehPremiado(retornaAutor(auxiliar->noticia))) {
            imprimeNoticia(auxiliar->noticia);
            printf("\n***** Hora de Publicação: %s", ctime(&auxiliar->horaPublicada));
        }
        auxiliar = auxiliar->next;
    }
}

//Retorna o número de notícias do jornal naquele momento
int retornaNumeroNoticias(Jornal* j) {
    if (!j) return 0;
    return j->numNoticias;
}

//Libera memória de todo jornal, inclusive das notícias.
void liberaJornal(Jornal* j) {
    if (!j) return;

    free(j->nome);
    Celula *auxiliar = j->first;
    while (auxiliar) {
        auxiliar = auxiliar->next;
        liberaNoticia(j->first->noticia);
        free(j->first);
        j->first = auxiliar;
    }
    free(j);
}
