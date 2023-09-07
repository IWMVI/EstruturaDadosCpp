#include "Aluno.h"

class Hash
{
private:
    int funcaoHash(Aluno aluno);
    int maxItens;
    int maxPosicoes;
    int qtdItens;
    Aluno *estrutura;

public:
    Hash(int tamVet, int max);
    ~Hash();
    bool isFull();
    int size();
    void push(Aluno aluno);
    void pop(Aluno aluno);
    void search(Aluno &aluno, bool &busca);
    void print();
};