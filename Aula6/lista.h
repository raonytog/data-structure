#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Lista Lista;

Lista *IniciaLista();

void InsereNaLista(Lista *lista, void *animal);

void RetiraDaLista(Lista *lista, void *animal);

void ImprimeLista(Lista *lista);

void LiberaLista(Lista *lista);

#endif