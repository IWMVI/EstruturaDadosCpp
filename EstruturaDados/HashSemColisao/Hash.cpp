#include <iostream>
#include "Hash.h"

using namespace std;

int Hash::funcaoHash(Aluno aluno)
{
    return (aluno.getRA() % maxPosicoes);
}
Hash::Hash(int tamVet, int max)
{
    qtdItens = 0;
    maxItens = max;
    maxPosicoes = tamVet;
    estrutura = new Aluno[tamVet];
}
Hash::~Hash()
{
    delete[] estrutura;
}
bool Hash::isFull()
{
    return (qtdItens == maxItens);
}
int Hash::size()
{
    return (qtdItens);
}
void Hash::push(Aluno aluno)
{
    int local = funcaoHash(aluno);
    estrutura[local] = aluno;
    qtdItens++;
}
void Hash::pop(Aluno aluno)
{
    int local = funcaoHash(aluno);
    if (estrutura[local].getRA() != -1)
    {
        estrutura[local] = Aluno(-1, " ");
        qtdItens--;
    }
}
void Hash::search(Aluno &aluno, bool &busca)
{
    int local = funcaoHash(aluno);
    Aluno aux = estrutura[local];
    if (aluno.getRA() != aux.getRA())
    {
        busca = false;
    }
    else
    {
        busca = true;
        aluno = aux;
    }
}
void Hash::print()
{
    cout << "Tabela Hash: \n\n";
    for (int i = 0; i < maxPosicoes; i++)
    {
        if (estrutura[i].getRA() != -1)
        {
            cout << "Posicao: " << i << endl;
            cout << "RA: " << estrutura[i].getRA() << endl;
            cout << "Nome: " << estrutura[i].getNome() << endl;
            cout << endl;
        }
    }
}