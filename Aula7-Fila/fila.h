#ifndef _FILA_H_
#define _FILA_H_

#include "amostra.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fila Fila;

Fila *IniciaFila();

void InsereFilaFinal(Fila *fila, Amostra *amostra);

void InsereFilaInicio(Fila *fila, Amostra *amostra);

Amostra *RetiraFila(Fila *fila);

void ImprimeFila(Fila *fila);

void Liberafila(Fila *fila);

int EstaVaziaLista(Fila *fila);

#endif