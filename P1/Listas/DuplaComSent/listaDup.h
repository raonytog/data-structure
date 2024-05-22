#ifndef _LISTADUP_H_
#define _LISTADUP_H_

typedef struct Lista Lista;

Lista *Inic();

void Push(Lista *list, int item);

int PopItem(Lista *list, int item);

void Destroy(Lista *list);

void PrintList(Lista *list);

#endif // !_LISTADUP_H_