#ifndef _LOJA_H_
#define _LOJA_H_

typedef struct Loja Loja;

Loja *CriaLoja(char *nome, int id, int qtdProdutos);

void ImprimeLoja(void *loja);

void LiberaLoja(void *loja);

char *RetornaNome(void *loja);

int RetornaId(void *loja) ;

int ComparaID(void *a1, void *a2);

#endif