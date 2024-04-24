#ifndef _CACHORRO_H_
#define _CACHORRO_H_

#define BRAVO 0
#define MANSO 1

typedef struct Cachorro Cachorro;

Cachorro *inicCachorro(char *nome, int nivelAgressividade);

void liberaCachorro(Cachorro *cachorro);

void imprimeCachorro(Cachorro *cachorro);

void atribuiNivelAgressividadeCachorro(Cachorro *cachorro, int nivelAgressividade);

#endif