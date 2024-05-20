#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula Celula;

struct aluno {
    char *nome;
    int matricula;
};

struct Celula {
    TAluno *aluno;
    Celula *next;
};

struct lista {
    Celula *first, *last;
};

/*Inicializa o sentinela de uma lista
 * inputs: nenhum
 * output: Sentinela inicializado (lista vazia)
 * pre-condicao: nenhuma
 * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL */
TLista* CriaLista() {
    TLista *lista = malloc(sizeof(TLista));
    lista->first = lista->last = NULL;
    return lista;
}

/*Inicializa um TipoItem aluno
 * inputs: o nome e a matricula do aluno
 * output: um ponteiro para o tipo TAluno criado
 * pre-condicao: nome e matricula validos
 * pos-condicao: tipo TAluno criado, com os campos nome e matricula COPIADOS */
TAluno* InicializaAluno(char* nome, int matricula) {
    if (!nome) return;

    TAluno *aluno = malloc(sizeof(TAluno));
    aluno->matricula = matricula;
    aluno->nome = strdup(nome);
    return aluno;
}

/*Insere um aluno na primeira posicao da lista de alunos
 * inputs: aluno a ser inserido na lista (do tipo TAluno) e a lista
 * output: nenhum
 * pre-condicao: aluno n�o NULL e lista n�o NULL (mas, a lista pode estar vazia)
 * pos-condicao: lista contem o aluno inserido na primeira posicao */
void InsereAluno (TLista* lista, TAluno* aluno) {
    if (!lista || !aluno) return;

    Celula *newAluno = malloc(sizeof(Celula));
    newAluno->aluno = aluno;
    newAluno->next = NULL;

    // se lista vazia
    if (!lista->first && !lista->last) {
        lista->first = lista->last = newAluno;
        return;
    }

    // demais
    newAluno->next = lista->first;
    lista->first = newAluno;
}

/*Retira a primeira ocorrencia de um aluno de matricula mat da lista de alunos
 * inputs: a lista e a matricula do aluno a ser retirado da lista
 * output: o aluno (do tipo TAluno) retirado da lista ou NULL, se o aluno nao se encontrar na lista
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem a primeira ocorrencia do aluno de matricula mat */
TAluno* Retira (TLista* lista, int mat) {
    if (!lista) return NULL;

    // vazia
    if (!lista->first && !lista->last) return NULL;

    Celula *auxiliar, *anterior;
    TAluno *aluno;

    // se o primeiro
    if (lista->first->aluno->matricula == mat) {
        auxiliar = lista->first->next;
        aluno = lista->first->aluno;
        free(lista->first);
        lista->first = auxiliar;
        return aluno;
    }

    auxiliar = lista->first;
    while (auxiliar) {
        if (auxiliar->aluno->matricula == mat) {
            aluno = auxiliar->aluno;
            anterior->next = auxiliar->next;
            free(auxiliar);
            return aluno;
        }
        anterior = auxiliar;
        auxiliar = auxiliar->next;
    }

    return NULL;
}

/* Retira as repeticoes na lista. Ou seja, deixa apenas uma referencia para cada aluno na lista
 * inputs: a lista
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem repeticoes de alunos - APENAS UMA OCORRENCIA DE CADA ALUNO */
void RetiraRepetidos (TLista* lista) {
    if (!lista) return;

    for (Celula *i = lista->first; i; i = i->next) {
        for (Celula *j = i->next; j; j = j->next) {
            if (i->aluno->matricula == j->aluno->matricula) {
                Celula *savePoint = i->next;
                Retira(lista, j->aluno->matricula);
                i = savePoint;
            }
        }
    }
}


/* Intercala os alunos das turmas 1 e 2 em uma nova lista. Por exemplo, se a turma 1 tiver (a1->a2->a3) e a turma 2 tiver (b1->b2->b3->b4->b5), a funcao deve retornar uma nova lista formada pelos elementos (a1->b1->a2->b2->a3->b3->b4->b5). Se uma das  listas tiver mais elementos que a outra, os elementos excedentes s�o transferidos na mesma ordem para a nova lista. As listas originais devem ficar vazias (com sentila prim e ult apontando para NULL).
 * inputs: duas listas n�o nulas (por�m, podem estar vazias)
 * output: uma nova lista com os elementos intercalados
 * pre-condicao: listas turma1 e turma2 nao sao NULL (mas podem estar vazias)
 * pos-condicao: lista retornada contem os elementos intercalados. As listas de entrada vazias (apenas com sentinela). */
TLista* Merge (TLista* turma1, TLista* turma2) {
    if (!turma1 || !turma2) return NULL;

    int qualTerminou = 0; // 1 se i, 2 se j
    TLista *ans = CriaLista();
    Celula *i, *j;
    for (i = turma1->first, j = turma2->first; i && j; i = i->next, j = j->next) {
        InsereAluno(ans, i->aluno);
        InsereAluno(ans, j->aluno);
    }

    if (i == NULL) qualTerminou = 1;
    else if (j == NULL) qualTerminou = 2;

    switch (qualTerminou) {
        case 1:
            for (;j; j = j->next)
                InsereAluno(ans, j->aluno);
            break;

        case 2:
            for (;i; i = i->next)
                InsereAluno(ans, i->aluno);
            break;
    }

    return ans;
}

/* Libera a memoria alocada para o aluno
 * inputs: o aluno do tipo TAluno*
 * output: nenhum
 * pre-condicao: aluno n�o NULL
 * pos-condicao: toda a memoria alocada para o aluno foi liberada (inclusive para o nome) */
void LiberaAluno (TAluno* aluno) {
    if (!aluno) return;

    free(aluno->nome);
    free(aluno);
    aluno = NULL;
}

/*Imprime os dados de todos os alunos da lista
 * inputs: a lista de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas, pode estar vazia)
 * pos-condicao: dados dos alunos impressos na saida padrao */
void Imprime (TLista* lista) {
    if (!lista) return;
    printf("Lista de alunos:\n");
    Celula *auxiliar = lista->first;
    while (auxiliar) {
        printf("\t%s - %d\n", auxiliar->aluno->nome, auxiliar->aluno->matricula);
        auxiliar = auxiliar->next;
    }
}

/*Libera toda a memoria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
 * inputs: a lista encadeada de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: toda memoria alocada eh liberada (use valgrind!) */
void LiberaLista (TLista* lista) {
    if (!lista) return;

    Celula *auxiliar = lista->first;
    while (auxiliar) {
        auxiliar = auxiliar->next;
        //LiberaAluno(lista->first->aluno); // erro pois o aluno ja foi liberado
        free(lista->first);
        lista->first = auxiliar;
    }
    free(lista);
}