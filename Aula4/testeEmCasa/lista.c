#include "lista.h"

struct Sentinela {
    Node *first;
    Node *last;
};

struct Node {
    Aluno *aluno;
    Node *next;
};

Sentinela *InicializaSentinela() {
    Sentinela *s = malloc(sizeof(Sentinela));
    s->first = NULL;
    s->last = NULL;
    return s;
}

Node * CriaNode(Aluno *aluno) {
    Node *node = malloc(sizeof(Node));
    node->aluno = aluno;
    node->next = NULL;
    return node;
}

int EstaVaziaLista(Sentinela * sentinela) {
    return !sentinela->first && !sentinela->last;
}

void LiberaSentinela(Sentinela * sentinela) {
    if (!sentinela) return;

    Node * tempNode = sentinela->first;
    while (tempNode) {
        tempNode = tempNode->next;
        LiberaNode(sentinela->first);
        sentinela->first = tempNode;
    }
    free(sentinela);
}

void LiberaNode(Node * node) {
    if (!node) return;
    //LiberaAluno(node->aluno);
    free(node);
}

void ImprimeLista(Sentinela * sentinela) {
    if (!sentinela) return;

    printf("----------------------Lista de Alunos ----------------------\n");
    Node * tempNode = sentinela->first;
    while (tempNode) {
        ImprimeAluno(tempNode->aluno);
        tempNode = tempNode->next;
    }
    printf("------------------------------------------------------------\n\n");
}

void RemoveAlunoLista(Sentinela * sentinela, int matricula) {
    Node *atual, *ant;

    // se a lista estiver vazia
    if (!EstaVaziaLista(sentinela)) return;

    // se so tiver uma pessoa na lista
    if (sentinela->first == sentinela->last) {
        atual = sentinela->first;

        if (ComparaMatricula(atual->aluno, matricula)) {
            sentinela->first = atual->next;
            LiberaNode(atual);
        }
    }

    // percorre a lista ate encontrar o aluno
    atual = sentinela->first;
    while (atual) {
        if (!ComparaMatricula(atual->aluno, matricula)) {
            ant = atual;
            atual = atual->next;
        }

        sentinela->first = atual->next;
        LiberaNode(atual);
        break;
    }
}

void AdicionaAlunoListaFinal(Sentinela * sentinela, Aluno * aluno) {
    // se nao tiver alocado espaco para as estruturas do parametro
    if (!sentinela || !aluno) return;

    // se a lista estiver vazia
    Node * node = CriaNode(aluno);
    if (EstaVaziaLista(sentinela)) sentinela->first = sentinela->last = node;

    // adiciona ao final da lista
    Node * antigo = sentinela->last;
    sentinela->last = node;
    antigo->next = sentinela->last;
}

void AdicionaAlunoListaInicio(Sentinela * sentinela, Aluno * aluno) {
    // se nao tiver alocado espaco para as estruturas do parametro
    if (!sentinela || !aluno) return;

    // se a lista estiver vazia
    Node * node = CriaNode(aluno);
    if (EstaVaziaLista(sentinela)) {
        sentinela->first = sentinela->last = node;
        return;
    }

    // adiciona ao comeco da lista
    Node * antigo = sentinela->first;
    sentinela->first = node;
    node->next = antigo;
}