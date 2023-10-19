#include "HashAlfabetica.h"
#include <iostream>

HashAlfabetica::HashAlfabetica(int tamVet, int max) : Hash(tamVet, max) {}

void HashAlfabetica::pesquisarPorLetra(char letra) const {
    // Implementação do método pesquisarPorLetra
    for (int i = 0; i < maxPosicoes; i++) {
        if (estrutura[i].getId() != 0 && estrutura[i].getNome()[0] == letra) {
            std::cout << "Posicao: " << i << std::endl;
            std::cout << "ID: " << estrutura[i].getId() << std::endl;
            std::cout << "Nome: " << estrutura[i].getNome() << std::endl << std::endl;
        }
    }
}

void HashAlfabetica::verificarOrdemAlfabetica() const {
    // Implementação do método verificarOrdemAlfabetica
    bool ordenado = true;
    for (int i = 1; i < maxPosicoes; i++) {
        if (estrutura[i].getId() != 0 && estrutura[i - 1].getId() != 0 &&
            estrutura[i].getNome() < estrutura[i - 1].getNome()) {
            ordenado = false;
            break;
        }
    }

    if (ordenado) {
        std::cout << "A Hash está em ordem alfabética." << std::endl;
    } else {
        std::cout << "A Hash não está em ordem alfabética." << std::endl;
    }
}

void HashAlfabetica::print() const {
    std::cout << "Tabela Hash Alfabética: \n";
    for (int i = 0; i < maxPosicoes; i++) {
        if (estrutura[i].getId() != 0) {
            std::cout << "Posicao: " << i << std::endl;
            std::cout << "ID: " << estrutura[i].getId() << std::endl;
            std::cout << "Nome: " << estrutura[i].getNome() << std::endl << std::endl;
        }
    }
}
