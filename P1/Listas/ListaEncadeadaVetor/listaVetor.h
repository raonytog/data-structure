#ifndef _LISTAVETOR_H_
#define _LISTAVETOR_H_

#define MAX 20

typedef struct Lista Lista;

Lista *Inic();

void Push(Lista *list, int item);

int PopItem(Lista *list, int item);

void Destroy(Lista *list);

void PrintList(Lista *list);

#endif // _LISTAVETOR_H_