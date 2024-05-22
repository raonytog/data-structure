#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Lista Lista;

Lista *CriaLista();

void Push(Lista *lista, char *palavra);

void Pop(Lista *lista, char *palavra);

void Libera(Lista *lista);

void Imprime(Lista *lista);

#endif // !_LISTA_H_
