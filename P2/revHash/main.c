#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hash.h"

int main () {
    Hash *ht = InitHash(13);
    
    HashInsert(ht, "raony");
    HashInsert(ht, "raony");
    HashInsert(ht, "raony");
    HashInsert(ht, "raony");
    HashInsert(ht, "malu");
    HashInsert(ht, "barbara");

    PrintHash(ht);
    DestroyHash(ht);
    return 0;
}