#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Lista Lista;

Lista *CriaLista();

void InsereLista(Lista *lista, void *animal, int tipo);

void RetiraLista(Lista *lista, void *animal);

void ImprimeLista(Lista *lista);

void LiberaLista(Lista *lista);

int RetornaQtdCachorros(Lista *lista);

int RetornaQtdGatos(Lista *lista);

#endif // !_LISTA_H_
