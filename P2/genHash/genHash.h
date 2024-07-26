#ifndef _GENHASH_H_
#define _GENHASH_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash Hash;

Hash *InitHashTable(size_t size, size_t object_size);

void *HashSearch(Hash *hash_table, 
                int(hash_function)(void*), int(*compare)(void*, void*));

void *InsertHash(Hash *hash_table, void *data, 
                int(hash_function)(void*), int(*compare)(void*, void*));

void DestroyHash(Hash *hash_table);

void PrintHash(Hash *hash_table, void(*print_function)(void*))


#endif // !_GENHASH_H_



