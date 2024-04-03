#include "lista.h"
#include "produto.h"

struct sentinela {
    Lista *primeiro, *ultimo;
};

struct lista {
    Produto *p;
    Lista *next;
};

Sentinela * CriaSentinela() {
    Sentinela * s = malloc(sizeof(Sentinela));
    s->primeiro = NULL;
    s->ultimo = NULL;
    return s;
}

Lista * CriaLista() {
    Lista * l = malloc(sizeof(Lista));
    return l;
}

void InsereProdutoLista(Sentinela *s, Produto *p) {
    Lista * temp = CriaLista();
    temp->p = p;

    if (!s->primeiro && !s->ultimo) {
        s->primeiro->p = p;    s->ultimo->p = p;
        return;
    }

    s->ultimo->next = temp;
    s->ultimo = temp;
    
}

void RetiraProdutoLista(Sentinela *s, int cod) {
    // se so tem um item na lista
    if (s->primeiro == s->ultimo) {
        if (cod == GetCodigoProduto(s->primeiro->p)) {
            LiberaProduto(s->primeiro->p);
            s->primeiro = NULL;
            s->ultimo = NULL;
            return;
        }
    }

    // se nao tem item na lista
    if (!s->primeiro && !s->ultimo) {
        return;
    }

    // verifica item a item da lista
    Lista *ant, *atual = s->primeiro;
    while (atual->next) {
        if (cod == GetCodigoProduto(atual->p)) {
            ant->next = atual->next;
            LiberaProduto(atual->p);
            return;
        }

        ant = atual;
        atual = atual->next;
    }
}

void ImprimeLista(Sentinela *s) {
    Lista *temp = s->primeiro;
    while (!temp->next) {
        ImprimeProduto(temp->p);
        temp = temp->next;
    }
}

void LiberaLista(Sentinela *s) {
    Lista *ant;
    while (!s->primeiro && !s->ultimo) {
        ant = s->primeiro->next;
        free(s->primeiro);
        s->primeiro = ant;
    }
} 


