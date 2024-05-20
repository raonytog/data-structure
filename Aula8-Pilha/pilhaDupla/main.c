#include "PilhaDupla.h"

#include <stdio.h>
#include <stdlib.h>

int main () {
    TipoPilhaDupla *pilha = init();
    Push(pilha, 10, PILHA1);
    Push(pilha, 20, PILHA1);
    Push(pilha, 30, PILHA1);
    Push(pilha, 40, PILHA1);

    Push(pilha, 50, PILHA2);
    Push(pilha, 6, PILHA2);
    Push(pilha, 7, PILHA2);
    Push(pilha, 80, PILHA2);
    Push(pilha, 900, PILHA2);
    Push(pilha, 200, PILHA2);

    TipoItem out;
    out = Pop(pilha, PILHA2);
    out = Pop(pilha, PILHA1);

    PrintStack(pilha);
    DestroyStack(pilha);


    return 0;
}