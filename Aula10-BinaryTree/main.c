
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main () {
    Aluno *raony = CriaAluno("Raony");
    Aluno *malu = CriaAluno("Malu");
    Aluno *marcela = CriaAluno("Marcela");
    Aluno *aline = CriaAluno("Aline");
    Aluno *gabriel = CriaAluno("Gabriel");
    Aluno *eduardo = CriaAluno("Eduardo");

    Arv *a = CriaArvore(raony, NULL, NULL);
    Arv *b = CriaArvore(malu, NULL, NULL);
    Arv *c = CriaArvore(aline, a, NULL);
    Arv *pai = CriaArvore(marcela, c, b);
    ImprimeArvore(pai);

    LiberaArvore(pai);

    LiberaAluno(raony);
    LiberaAluno(malu);
    LiberaAluno(marcela);
    LiberaAluno(aline);
    LiberaAluno(gabriel);
    LiberaAluno(eduardo);
    
    return 0;
}