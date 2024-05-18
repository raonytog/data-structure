#include "lista.h"

typedef Celula Lista;

struct Celula {
    Celula *prox;
    Celula *ant;
    Produto *produto;
};

Lista* CriaLista() {
    Lista *c = NULL;
    return c;
}

void LiberaLista(Lista *lista) {
    if (!lista) return;
    
    Lista *aux;
    for (;lista;) {
        aux = lista->prox;
        free(lista);
        lista = aux;
    }
}

void ImprimeLista(Celula *lista) {
    if (!lista) return;
    printf("==================================================\n");
    Lista *aux = lista;
    for (;aux;) {
        ImprimeProduto(aux->produto);
        aux = aux->prox;
    }
    printf("==================================================\n\n");
}

Lista* InsereProdutoLista(Lista *lista, Produto *p) {
    Lista *new = malloc(sizeof(Lista));
    new->produto = p;
    printf("\tInserido produto '%s' com sucesso!\n", GetNomeProduto(p));

    // se a lista estiver vazia
    if (!lista) {
        new->prox = new->ant = NULL;
        return new;
    }

    // caso tenha mais items na lista
    new->prox = lista;
    lista->ant = new;
    return new;
}

Lista* RetiraProdutoLista(int cod, Lista *lista) {
    // lista vazia
    if (!lista) return NULL;

    Lista *new;
    if (GetCodigoProduto(lista->produto) == cod) {
        printf("\tRemovido produto '%s' com sucesso!\n", GetNomeProduto(lista->produto));
        new = lista->prox;
        new->ant = NULL;
        free(lista);
        return new;
    }

    // verifica todos os items da lista
    for (new = lista->prox; new; new = new->prox) {
        if (GetCodigoProduto(new->produto) == cod) {
            printf("\tRemovido produto '%s' com sucesso!\n", GetNomeProduto(new->produto));
            new->ant->prox = new->prox;
            if (new->prox) new->prox->ant = new->ant;
            free(new);
            return lista;
        }
    }

    return lista;
}
