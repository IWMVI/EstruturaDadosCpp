#include "Pessoa.h"

Pessoa::Pessoa() : id(0), nome("") {}

Pessoa::Pessoa(int newId, const std::string &newName) : id(newId), nome(newName) {}

int Pessoa::getId() const
{
    return id;
}

const std::string &Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setId(int newId)
{
    id = newId;
}

void Pessoa::setNome(const std::string &newName)
{
    nome = newName;
}
