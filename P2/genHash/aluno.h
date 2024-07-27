#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct Aluno Aluno;

Aluno *InitAluno(char *nome, int matricula);

char *GetAlunoNome(void *aluno);

int GetAlunoMatricula(void *aluno);

void PrintAluno(void *aluno);

void LiberaAluno(void *aluno);

int ComparaMatriculaAlunos(void *a1, void *a2);

int ComparaNomeAlunos(void *a1, void *a2);

#endif