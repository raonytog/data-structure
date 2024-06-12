#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct Aluno Aluno;

Aluno *CriaAluno(char *nome);

void ImprimeAluno(Aluno *aluno);

void LiberaAluno(Aluno *aluno);

char *RetornaNome(Aluno *aluno);

#endif