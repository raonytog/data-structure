#ifndef _ARV_H_
#define _ARV_H_

typedef struct Arv Arv;

#include "aluno.h"

Arv *cria_arvore();

Arv *insere_aluno_arvore(Arv *a, Aluno *aluno);

Arv *retira_aluno_arvore(Arv *a, int id);

void imprime_arvore(Arv *a);

int busca_binaria(Arv *a, int id);


#endif