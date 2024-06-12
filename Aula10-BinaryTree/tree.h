#ifndef _TREE_H_
#define _TREE_H_

#include "aluno.h"

typedef struct Arv Arv;

Arv *CriaArvore(Aluno *aluno, Arv *left, Arv *right);

void LiberaArvore(Arv *a);

int EhArvoreVazia(Arv *a);

int AlunoPercenteArvore(Arv *a, Aluno *aluno);

void ImprimeArvore(Arv *a);


int folhas(Arv *a); 

int ocorrencias(Arv *a, Aluno *aluno);

int altura(Arv *a);

#endif