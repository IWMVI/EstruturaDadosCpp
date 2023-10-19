#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa
{
public:
    Pessoa(); // Construtor padrão
    Pessoa(int newId, const std::string &newName);

    int getId() const;
    const std::string &getNome() const;

    void setId(int newId);
    void setNome(const std::string &newName);

private:
    int id;
    std::string nome;
};

#endif // PESSOA_H
