#ifndef _CACHORRO_H_
#define _CACHORRO_H_

#define BRAVO 1
#define MANSO 0

#define CACHORRO 10

typedef struct Cachorro Cachorro;

Cachorro *inicCachorro(char *nome, int nivelAgressividade);

void liberaCachorro(Cachorro *cachorro);

void imprimeCachorro(Cachorro *cachorro);

void atribuiNivelAgressividadeCachorro(Cachorro *cachorro, int nivelAgressividade);

int getNivelAgressividadeCachorro(Cachorro *cachorro);

#endif