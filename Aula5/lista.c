#include "lista.h"

typedef Celula Lista;

struct Celula {
    Celula *prox;
    Celula *ant;
    Produto *produto;
};


Lista* CriaLista() {
    Lista *c = malloc(sizeof(Lista));
    if (!c) return NULL;
    c->ant = c->prox = NULL;
    c->produto = NULL;
    return c;
}

void LiberaLista(Lista *lista) {
    if (!lista) return;
    Lista *aux = lista->ant;
    for (;aux->prox;) {
        if (aux) {
            LiberaProduto(aux->produto);
            aux = aux->prox;
            free(aux);
        }
    }
}

void ImprimeLista(Celula *lista) {
    if (!lista) return;
    Lista *aux = lista;
    for (;aux;) {
        ImprimeProduto(aux->produto);
        aux = aux->prox;
    }
}

Lista* InsereProdutoLista(Lista *lista, Produto *p) {
    if (!p) return NULL;

    Lista *new = CriaLista();
    new->produto = p;

    // se n tiver nada na lista
    if (!lista->produto) {
        return new;
    }

    // se so tiver um item
    if (!lista->prox) {
        new->prox->ant = new;
    } 

    lista->ant = new;
    new->ant = NULL;
    return new;
}

Lista* RetiraProdutoLista(int cod, Lista *lista) {
    // lista nao existe
    if (!lista) return NULL;

    // se eh o primeiro
    if (GetCodigoProduto(lista->produto) == cod) {
        lista = lista->prox;
        return lista;
    }

    // resto
    Lista *aux;
    for (aux = lista; aux->prox != NULL; aux = aux->prox) {
        if (GetCodigoProduto(aux->produto) == cod) {
            aux->ant = aux->prox;
            break;
        }
    }

    lista = aux;
    return lista;
}