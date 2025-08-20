#ifndef _PAIS_H_
#define _PAIS_H_

/**
 * Raony Togneri Gomes
*/

#include <stdio.h>

typedef struct Pais Pais;

Pais *InitPais(char *nome, int ouro, int prata, int bronze, int total);

char *getPaisName(Pais *p);

void DestroyPais(Pais *p);

void PrintPais(Pais *p);

void AtualizaInformacoesPais(Pais *p, int ouro, int prata, int bronze, int total);

int ComparaMedalhasOuro(const void *a, const void *b);

int ComparaMedalhasPrata(const void *a, const void *b);

int ComparaMedalhasBronze(const void *a, const void *b);

void SortPaises(Pais **vetor, int size, FILE *arquivo);

#endif