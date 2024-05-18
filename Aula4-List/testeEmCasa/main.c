#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "aluno.h"

int main () {
    Sentinela * lista = InicializaSentinela();

    Aluno * raony = CriaAluno("Raony", 1, 001);
    Aluno * gabriel = CriaAluno("Gabriel", 2, 002);
    Aluno * eduardo = CriaAluno("Eduardo", 3, 003);
    Aluno * marcela = CriaAluno("Marcela", 4, 004);
    Aluno * malu = CriaAluno("Malu", 5, 005);
    Aluno * aline = CriaAluno("Aline", 6, 006);
    Aluno * barbara = CriaAluno("Barbara", 7.0, 007);

    AdicionaAlunoListaInicio(lista, raony);
    AdicionaAlunoListaInicio(lista, barbara);
    ImprimeLista(lista);

    AdicionaAlunoListaFinal(lista, malu);
    AdicionaAlunoListaInicio(lista, aline);
    AdicionaAlunoListaInicio(lista, marcela);
    ImprimeLista(lista);

    AdicionaAlunoListaFinal(lista, gabriel);
    AdicionaAlunoListaFinal(lista, eduardo);

    LiberaSentinela(lista);

    LiberaAluno(raony);     LiberaAluno(gabriel);       LiberaAluno(eduardo);
    LiberaAluno(marcela);   LiberaAluno(malu);          LiberaAluno(aline);
    LiberaAluno(barbara);


    return 0;
}