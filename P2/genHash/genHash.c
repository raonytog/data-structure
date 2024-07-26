#include "genHash.h"

struct hash {
    void **data;
    size_t max_size;
    size_t real_size;
};

Hash *InitHashTable(size_t size, size_t object_size) {
    if (size <= 0 || object_size <= 0) return NULL;

    Hash *new = malloc(sizeof(Hash));
    new->max_size = size;
    new->real_size = 0;

    new->data = calloc(size, sizeof(object_size));
    for (size_t i = 0; i < size; i++)
        new->data[i] = calloc(1, sizeof(object_size));

    return new;
}

void *HashSearch(Hash *hash_table, 
                int(*hash_function)(void*), int(*compare)(void*, void*)) {
    if (!hash_table || !hash_function || !compare) return;


}

void *InsertHash(Hash *hash_table, void *data, 
                int(*hash_function)(void*), int(*compare)(void*, void*));

void DestroyHash(Hash *hash_table);

void PrintHash(Hash *hash_table, void(*print_function)(void*)) {

}