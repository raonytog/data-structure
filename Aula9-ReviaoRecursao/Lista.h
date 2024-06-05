#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Lista Lista;

Lista *CriaLista();

Lista *RetiraLista(Lista *lista, int tem);

Lista *InsereLista(Lista *lista, int item);

void ImprimeLista(Lista *lista);


#endif //  _LISTA_H_