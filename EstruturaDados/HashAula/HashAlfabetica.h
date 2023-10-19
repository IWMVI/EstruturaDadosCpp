#ifndef HASH_ALFABETICA_H
#define HASH_ALFABETICA_H

#include "Hash.h"

class HashAlfabetica : public Hash {
public:
    HashAlfabetica(int tamVet, int max);
    void pesquisarPorLetra(char letra) const;
    void verificarOrdemAlfabetica() const override;
    void print() const override;
};

#endif // HASH_ALFABETICA_H
