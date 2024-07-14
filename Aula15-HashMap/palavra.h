#ifndef _PALAVRA_H_
#define _PALAVRA_H_

typedef struct palavra Palavra;

Palavra *criaPalavra(char *string);

char *retornaPalavra(Palavra *palavra);

int retornaFrequencia(Palavra *palavra);

void incrementaFrequencia(Palavra *palavra);

void imprimePalavra(Palavra *palavra);

void liberaPalavra(Palavra *palavra);

#endif // !_PALAVRA_H_
