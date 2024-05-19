#include "nPilhas.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    TipoPilhaMultipla *stack = Init();
    PushStack(stack, 9999, STACK1);
    PushStack(stack, 20, STACK1);
    PushStack(stack, 303, STACK2);
    PushStack(stack, 500, STACK6);
    PushStack(stack, 234, STACK9);
    PushStack(stack, 777, STACK7);
    PushStack(stack, 777, STACK7);
    PrintStack(stack);
    printf("\n\n");

    PopStack(stack, STACK1);
    PopStack(stack, STACK7);
    PrintStack(stack);

    DestroyStack(stack);
    return 0;
}