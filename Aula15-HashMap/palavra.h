#ifndef _PALAVRA_H_
#define _PALAVRA_H_

typedef struct Palavra Palavra;

Palavra *InicPalavra(char *pal);

char *RetornaPalavra(Palavra *pal);

int RetornaOcorrencias(Palavra *pal);

void IncrementaOcorrencia(Palavra *pal);

Palavra *LiberaPalavra(Palavra *pal);

#endif