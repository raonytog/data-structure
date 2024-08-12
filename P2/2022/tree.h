#ifndef _TREE_H_
#define _TREEH_H_

typedef struct Tree Tree;

Tree *InitTree();

Tree *InsertOnTree(Tree *arv, char *palavra);

void DestroyTree(Tree *arv);

void PrintTree(Tree *arv);

int get_qtd_nodes(Tree *arv);

int get_frequencia_palavra(Tree *arv, char *palavra);

void preenche_palavras_distintas(Tree *arvore, char **palavras, int *idx);



#endif // !_