#include "Hash.h"
#include <iostream>

Hash::Hash(int tamVet, int max) : qtdItens(0), maxItens(max), maxPosicoes(tamVet) {
    estrutura = new Pessoa[tamVet];
}

Hash::~Hash() {
    delete[] estrutura;
}

void Hash::push(const Pessoa& pessoa) {
    if (qtdItens < maxItens) {
        int local = pessoa.getId() % maxPosicoes;
        while (estrutura[local].getId() != 0) {
            local = (local + 1) % maxPosicoes; // Tratamento de colisão linear
        }
        estrutura[local] = pessoa;
        qtdItens++;
    } else {
        std::cout << "A estrutura está cheia. Não é possível adicionar mais elementos." << std::endl;
    }
}

void Hash::pop(const Pessoa& pessoa) {
    int local = pessoa.getId() % maxPosicoes;
    while (estrutura[local].getId() != 0) {
        if (estrutura[local].getId() == pessoa.getId()) {
            estrutura[local] = Pessoa(); // Reinicializa a posição
            qtdItens--;
            break;
        }
        local = (local + 1) % maxPosicoes; // Tratamento de colisão linear
    }
}

Pessoa Hash::search(int id) const {
    int local = id % maxPosicoes;
    while (estrutura[local].getId() != 0) {
        if (estrutura[local].getId() == id) {
            return estrutura[local];
        }
        local = (local + 1) % maxPosicoes; // Tratamento de colisão linear
    }
    return Pessoa(); // Pessoa não encontrada
}

bool Hash::isFull() const {
    return (qtdItens == maxItens);
}

void Hash::print() const {
    std::cout << "Tabela Hash: \n";
    for (int i = 0; i < maxPosicoes; i++) {
        if (estrutura[i].getId() != 0) {
            std::cout << "Posicao: " << i << std::endl;
            std::cout << "ID: " << estrutura[i].getId() << std::endl;
            std::cout << "Nome: " << estrutura[i].getNome() << std::endl << std::endl;
        }
    }
}
