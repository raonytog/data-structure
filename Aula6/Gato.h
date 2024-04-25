#ifndef _GATO_H_
#define _GATO_H_

#define BRAVO 1
#define MANSO 0

#define GATO 100

typedef struct Gato Gato;

Gato *inicGato(char *nome, int nivelAgressividade);

void liberaGato(Gato *gato);

void imprimeGato (Gato *gato);

void atribuiNivelAgressividadeGato(Gato *gato, int nivelAgressividade);

int getNivelAgressividadeGato(Gato *gato);

#endif