#ifndef _TABELAROT_H_
#define _TABELOROT_H_

typedef struct Hash Hash;
typedef struct Pacote Pacote;

Hash *CriaHash(int size);
int HashFunction(char *key, int size);
void HashSearch(Hash *h, char *palavra);
void InsereHash(Hash *h, char *key);
void LiberaHash(Hash *h);
void ImprimeHash(Hash *h);

Pacote *InitPacote(int nxtHop);
void LiberaPacote(Pacote *pacote);
void ImprimePacotes(Pacote *pacote);

#endif