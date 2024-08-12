#ifndef _PESSOA_H_
#define _PESSOA_H_

typedef struct Pessoa Pessoa;

Pessoa *InitPessoa(char *nome);

char *getNomePessoa(Pessoa *pessoa);

int getPresenca(Pessoa *pessoa);

int getFalta(Pessoa *pessoa);

void IncrementaPresenca(Pessoa *pessoa);

void IncrementaFalta(Pessoa *pessoa);

void DestroiPessoa(Pessoa *pessoa);

void ImprimePessoa(Pessoa *pessoa);

#endif // !_PESSOA_H_
