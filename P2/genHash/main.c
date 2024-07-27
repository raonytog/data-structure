#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genHash.h"
#include "aluno.h"

int hf_matricula(void *data, int size) {
    if (size <= 0) return -1;

    int key = data;
    return key%size;
}

int hf_nome(void *data, int size) {
    if (size<=0) return -1;

    char *key = data;
    int total = 0;
    for(int i=0;i<strlen(key);i++) total+=key[i];
    return total%size;
}

int main () {
    /** Alunos criados */
    Aluno *raony = InitAluno("raony", 10);
    Aluno *malu = InitAluno("malu", 23);
    Aluno *barbara = InitAluno("barbara", 19);
    Aluno *eduardo = InitAluno("eduardo", 2);
    Aluno *marcela = InitAluno("marcela", 9);
    Aluno *aline = InitAluno("aline", 3);
    Aluno *gabriel = InitAluno("gabriel", 13);

    /** Insere os alunos na tabela por nome*/
    Hash *ht = InitHash(10);
    HashInsert(ht, "raony", raony, hf_nome);
    HashInsert(ht, "malu", malu, hf_nome);
    HashInsert(ht, "barbara", barbara, hf_nome);
    HashInsert(ht, "eduardo", eduardo, hf_nome);
    HashInsert(ht, "marcela", marcela, hf_nome);
    HashInsert(ht, "aline", aline, hf_nome);

    /** pois o criterio eh a matricula */
    HashInsert(ht, 13, gabriel, hf_matricula); 

    /** Teste de sobreposicao de indice (aline ao contrario) */
    Aluno *enila = InitAluno("enila", 4);
    HashInsert(ht, "enila", enila, hf_nome);

    /** 
     * Procura o aluno com o criterio do nome, 
     * (o que foi passado a ele na hora de inserir na tabela) 
     */
    Aluno *encontrado = HashSearch(ht, "raony", hf_nome, ComparaNomeAlunos);
    if (encontrado) {
        printf("\nAluno encontrado:\n\t");
        PrintAluno(encontrado);
        printf("\n");
    }

    /** 
     * Procura o aluno com o criterio da matricula agora
     * (mesma justificativa)
     */
    encontrado = HashSearch(ht, 13, hf_matricula, ComparaMatriculaAlunos);
    if (encontrado) {
        printf("\nAluno encontrado:\n\t");
        PrintAluno(encontrado);
        printf("\n");
    }

    ImprimeHash(ht, PrintAluno);
    LiberaHash(ht);

    LiberaAluno(raony);     LiberaAluno(malu);      LiberaAluno(barbara);
    LiberaAluno(eduardo);   LiberaAluno(marcela);   LiberaAluno(aline);
    LiberaAluno(gabriel);   LiberaAluno(enila);

    return 0;
}