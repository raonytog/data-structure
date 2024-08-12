#include "pessoa.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char *nome;
    int presenca, falta;
};

Pessoa *InitPessoa(char *nome) {
    if (!nome) return NULL;
    Pessoa *new = malloc(sizeof(Pessoa));
    new->falta = new->presenca = 0;
    new->nome = strdup(nome);
    return new;
}

char *getNomePessoa(Pessoa *pessoa) {
    if (!pessoa) return '\0';
    return pessoa->nome;
}

int getPresenca(Pessoa *pessoa) {
    if (!pessoa) return -1;
    return pessoa->presenca;
}

int getFalta(Pessoa *pessoa) {
    if (!pessoa) return -1;
    return pessoa->falta;
}

void IncrementaPresenca(Pessoa *pessoa) {
    if (!pessoa) return;
    pessoa->presenca++;
}

void IncrementaFalta(Pessoa *pessoa) {
    if (!pessoa) return;
    pessoa->falta++;
}

void DestroiPessoa(Pessoa *pessoa) {
    if (!pessoa) return;
    free(pessoa->nome);
    free(pessoa);
}

void ImprimePessoa(Pessoa *pessoa) {
    if (!pessoa) return;
    printf("%s %dP %dF\n", pessoa->nome, pessoa->presenca, pessoa->falta);
}