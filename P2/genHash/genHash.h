#ifndef _GENHASH_H_
#define _GENHASH_H_

typedef struct Hash Hash;


typedef int(*compare)(void*, void*); /* compare(type *object1, type *object2) */
typedef int(*hfunction)(void*, int); /* hash(char *key, char *maxSize) */
typedef void(*destroy)(void*); /*libera(type *object) */
typedef void (*printhash)(void*); /* print(type *object) */

Hash *InitHash(int max_size);

void *HashSearch(Hash *hashtable, void *key, hfunction hash_func, compare comp_func);

void HashInsert(Hash *hashtable, void *key, void *object, hfunction hash_func);

void ImprimeHash(Hash *hashtable, printhash print_func);

void LiberaHash(Hash *hashtable);


#endif