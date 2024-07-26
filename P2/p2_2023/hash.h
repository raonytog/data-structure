#ifndef _HASH_H_
#define _HASH_H_

#include "pessoa.h"

typedef struct hash Hash;

Hash *InitHash(int size);

int HashFunction(char *key, int size);

void HashSearch(Hash *hashtable, char *key, char value);

Hash *InsertHash(Hash *hashtable, Pessoa *pessoa);

void PrintHash(Hash *hashtable);

void DestroyHash(Hash *hashtable);

#endif // !_HASH_H_