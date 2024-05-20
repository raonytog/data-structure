#ifndef _LISTADUPSS_H_
#define _LISTADUPSS_H_

typedef struct Lista Lista;

Lista *Push(Lista *list, int item);

Lista *PopItem(Lista *list, int item);

void Destroy(Lista *list);

void PrintList(Lista *list);

#endif // !_LISTADUPSS_H_