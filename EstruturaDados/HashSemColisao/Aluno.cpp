#include "Aluno.h"

Aluno::Aluno()
{
    ra = -1;
    nome = " ";
}
Aluno::Aluno(int r, string n)
{
    ra = r;
    nome = n;
}
int Aluno::getRA()
{
    return ra;
}
string Aluno::getNome()
{
    return nome;
}