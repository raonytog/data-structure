#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "palavra.h"

int main () {
    Hash *hash_table = initHash(10);
    FILE *fTexto = fopen("texto.txt", "r");
    
    char palavra[256];
    while(fscanf(fTexto, "%s ", palavra) == 1) {
        insertHash(hash_table, palavra);
    }

    printHash(hash_table);
    printf("\n");

    return 0;
}