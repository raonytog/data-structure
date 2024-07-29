#ifndef _HASH_H_
#define _HASH_H_

typedef struct Hash Hash;


Hash *InitHash(int size);

void HashInsert(Hash *ht, char *palavra);

int HashSearch(Hash *ht, char *palavra);

void PrintHash(Hash *ht);

void DestroyHash(Hash *ht);


#endif // !_HASH_H_
