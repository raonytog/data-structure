#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabelaRot.h"

int main () {
    Hash *htable = CriaHash(10);

    InsereHash(htable, "ranone");
    InsereHash(htable, "malu");
    InsereHash(htable, "barbara");
    InsereHash(htable, "aline");
    InsereHash(htable, "eduardo");
    InsereHash(htable, "gabriel");
    InsereHash(htable, "marcela");

    ImprimeHash(htable);

    char palavra[256]; 
    while( scanf("%s", palavra) == 1 ) {
        HashSearch(htable, palavra);
    }

    LiberaHash(htable);

    return 0;
}