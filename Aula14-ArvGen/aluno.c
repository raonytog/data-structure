
// #include "aluno.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Aluno {
//     char *nome;
//     int id;
// };

// Aluno *CriaAluno(char *nome, int id) {
//     Aluno *a = malloc(sizeof(Aluno));
//     if (!a) return NULL;

//     a->nome = strdup(nome);
//     a->id = id;
    
//     return a;
// }

// void ImprimeAluno(void *aluno) {
//     if (!aluno) return;

//     Aluno *new = (Aluno*) aluno;
//     printf("%s ", new->nome);
// }

// void LiberaAluno(void *aluno) {
//     if (!aluno) return;

//     Aluno *new = (Aluno*) aluno;
//     free(new->nome);
//     free(new);
// }

// char *RetornaNome(void *aluno) {
//     if (!aluno) return '\0';
    
//     Aluno *new = (Aluno*) aluno;
//     return new->nome;
// }

// int RetornaId(void *aluno) {
//     if (!aluno) return -1;

//     Aluno *new = (Aluno*) aluno;
//     return new->id;
// }

// int ComparaID(void *a1, void *a2) {
//     Aluno *new1 = (Aluno*) a1;
//     Aluno *new2 = (Aluno*) a2;

//     return new2->id - new1->id;
// }