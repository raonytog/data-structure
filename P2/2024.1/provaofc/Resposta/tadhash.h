#ifndef _HASH_h
#define _HASH_H_

#include "pais.h"

/**
 * Raony Togneri Gomes
*/

#define HASH_MAX 17

typedef struct Hash Hash;

Hash *InitHash();

void InsertHash(Hash *ht, Pais *pais);

Pais *SearchHash(Hash *ht, char *nome);

void PrintHash(Hash *ht);

void DestroyHash(Hash *ht);

int getHashSize(Hash *ht);

void FillVector(Hash *ht, Pais **vector);

#endif