#ifndef HASH_H
#define HASH_H

#include "Pessoa.h"

class Hash {
public:
    Hash(int tamVet, int max);
    virtual ~Hash();

    void push(const Pessoa& pessoa);
    void pop(const Pessoa& pessoa);
    Pessoa search(int id) const;
    bool isFull() const;
    virtual void print() const = 0;  
    virtual void verificarOrdemAlfabetica() const = 0;

protected:
    int maxItens;
    int qtdItens;
    int maxPosicoes;
    Pessoa* estrutura;
};

#endif // HASH_H
