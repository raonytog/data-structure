#ifndef _HASH_H_
#define _HASH_H_

typedef struct cell Cell;
typedef struct hash Hash;

Hash *initHash(int size);

int hashFunction(char *palavra, int size);

void insertHash(Hash *hashTable, char *palavra);

void printHash(Hash *hashTable);

void destroyHash(Hash *hashTable);

void ImprimeCelula(Cell *celula);
void LiberaCelula(Cell *celula);

#endif 