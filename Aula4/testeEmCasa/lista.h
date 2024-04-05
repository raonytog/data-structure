#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct Sentinela Sentinela;
typedef struct Node Node;

Sentinela * InicializaSentinela();

int EstaVaziaLista(Sentinela * sentinela);

void LiberaSentinela(Sentinela * sentinela);

void LiberaNode(Node * node);

void ImprimeLista(Sentinela * sentinela);

void RemoveAlunoLista(Sentinela * sentinela, int matricula);

void AdicionaAlunoListaFinal(Sentinela * sentinela, Aluno * aluno);

void AdicionaAlunoListaInicio(Sentinela * sentinela, Aluno * aluno);

#endif // !_LISTA_H_