#ifndef _HASH_H_
#define _HASH_H_

#include "palavra.h"

typedef struct Hash Hash;

Hash *InicializaHash(int size);

void InsereHash(Hash *h, Palavra *p);

Palavra *BuscaPalavra(Hash *h, char *string);

void LiberaHash(Hash *h);

#endif