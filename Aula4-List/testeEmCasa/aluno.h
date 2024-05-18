#ifndef _ALUNO_H_
#define _ALUNO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno Aluno;

Aluno * CriaAluno(char *nome, float CR, int matricula);

void LiberaAluno(Aluno *aluno);

void ImprimeAluno(Aluno *aluno);

int ComparaMatricula (Aluno *a, int matricula);

#endif // !_ALUNO_H_