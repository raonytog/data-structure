/**
 * Raony Togneri Gomes, 05 de julho, 2024 
 * UFES, Estrutura de Dados (3o semestre)
 */


#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Lista Lista;

Lista *CriaLista();

Lista *RetiraLista(Lista *lista, int tem);

Lista *InsereLista(Lista *lista, int item);

void ImprimeLista(Lista *lista);

void LiberaLista(Lista *lista);


#endif //  _LISTA_H_