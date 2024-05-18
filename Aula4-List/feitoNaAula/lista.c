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

Lista * CriaLista(Produto *p) {
    Lista * l = malloc(sizeof(Lista));
    l->next = NULL;
    l->p = p;
    return l;
}

int EhListaVazia(Sentinela *s) {
    return !s->primeiro && !s->ultimo;
}

void InsereProdutoLista(Sentinela *s, Produto *p) {
    if (!p || !s) return;

    Lista *node = CriaLista(p);
    if (!s->primeiro && !s->ultimo) {
        s->primeiro = s->ultimo = node;
        return;
    }

    Lista * antigo = s->ultimo;
    s->ultimo = node;
    antigo->next = s->ultimo;
}

void RetiraProdutoLista(Sentinela *s, int cod) {
    // se so tem um item na lista
    if (s->primeiro == s->ultimo) {
        if (cod == GetCodigoProduto(s->primeiro->p)) {
            LiberaLista(s->primeiro);
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
            LiberaLista(atual);
            return;
        }

        ant = atual;
        atual = atual->next;
    }
}

void ImprimeLista(Sentinela *s) {
    printf("-------------------- Lista de Produtos --------------------\n");
    Lista *node = s->primeiro;
    while (node) {
        ImprimeProduto(node->p);
        node = node->next;
    }
    printf("------------------------------------------------------------\n\n");
}

void LiberaSentinela(Sentinela *s) {
    if (!s) return;

    Lista *node = s->primeiro;
    while (node) {
        node = node->next;
        LiberaLista(s->primeiro);
        s->primeiro = node;
    }
    free(s);
} 

void LiberaLista(Lista *l) {
    if (!l) return;
    free(l);
}

