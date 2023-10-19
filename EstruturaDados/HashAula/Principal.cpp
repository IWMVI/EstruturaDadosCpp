#include <iostream>
#include "HashAlfabetica.h"
#include "Hash.h"
#include "Pessoa.h"

void exibirMenu();
void tratarHash(Hash& hash, std::istream& input);
void exibirMenuHash(Hash& hash);
void adicionarPessoa(Hash& hash, std::istream& input);
void pesquisarPessoa(const Hash& hash, std::istream& input);
void removerPessoa(Hash& hash, std::istream& input);
void verificarCheio(const Hash& hash);
void verificarOrdemAlfabetica(HashAlfabetica& hash);

int main() {
    HashAlfabetica hashAlfabetica(26, 26);
    HashAlfabetica hashNomes(50, 50);
    HashAlfabetica hashLista(100, 100);

    int opcao;
    do {
        exibirMenu();

        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                tratarHash(hashAlfabetica, std::cin);
                break;
            case 2:
                tratarHash(hashNomes, std::cin);
                break;
            case 3:
                tratarHash(hashLista, std::cin);
                break;
            case 0:
                std::cout << "Saindo do programa." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }

    } while (opcao != 0);

    return 0;
}


void exibirMenu() {
    std::cout << "\nMenu:" << std::endl;
    std::cout << "1. Tratar Hash Alfabética" << std::endl;
    std::cout << "2. Tratar Hash Nomes" << std::endl;
    std::cout << "3. Tratar Hash Lista" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << std::endl;
}

void tratarHash(Hash& hash, std::istream& input) {
    int opcao;
    do {
        exibirMenuHash(hash);

        std::cout << "Escolha uma opção: ";
        input >> opcao;

        switch (opcao) {
            case 1:
                adicionarPessoa(hash, input);
                break;
            case 2:
                pesquisarPessoa(hash, input);
                break;
            case 3:
                removerPessoa(hash, input);
                break;
            case 4:
                verificarCheio(hash);
                break;
            case 5:
                hash.print();
                break;
            case 6:
                if (auto* hashAlfabetica = dynamic_cast<HashAlfabetica*>(&hash)) {
                    hashAlfabetica->print();
                } else {
                    std::cout << "Essa operação só é válida para a Hash Alfabética." << std::endl;
                }
                break;
            case 7:
                if (auto* hashAlfabetica = dynamic_cast<HashAlfabetica*>(&hash)) {
                    std::cout << "Digite a letra para pesquisar: ";
                    char letra;
                    input >> letra;
                    hashAlfabetica->pesquisarPorLetra(letra);
                } else {
                    std::cout << "Essa operação só é válida para a Hash Alfabética." << std::endl;
                }
                break;
            case 8:
                if (auto* hashAlfabetica = dynamic_cast<HashAlfabetica*>(&hash)) {
                    verificarOrdemAlfabetica(*hashAlfabetica);
                } else {
                    std::cout << "Essa operação só é válida para a Hash Alfabética." << std::endl;
                }
                break;
            case 0:
                std::cout << "Saindo do tratamento da Hash." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }

    } while (opcao != 0);
}

void exibirMenuHash(Hash& hash) {
    std::cout << "\nMenu da Hash:" << std::endl;
    std::cout << "1. Adicionar Pessoa" << std::endl;
    std::cout << "2. Pesquisar Pessoa" << std::endl;
    std::cout << "3. Remover Pessoa" << std::endl;
    std::cout << "4. Verificar se está cheio" << std::endl;
    std::cout << "5. Imprimir" << std::endl;

    if (dynamic_cast<HashAlfabetica*>(&hash) != nullptr) {
        std::cout << "6. Imprimir em Ordem Alfabética" << std::endl;
        std::cout << "7. Pesquisar por Letra" << std::endl;
        std::cout << "8. Verificar Ordem Alfabética" << std::endl;
    }

    std::cout << "0. Sair do tratamento da Hash" << std::endl;
    std::cout << std::endl;
}

void adicionarPessoa(Hash& hash, std::istream& input) {
    std::cout << "Digite o ID da pessoa: ";
    int id;
    input >> id;
    std::cout << "Digite o nome da pessoa: ";
    input.ignore(); // Limpar o buffer
    std::string nome;
    std::getline(input, nome);

    Pessoa pessoa(id, nome);
    hash.push(pessoa);
    std::cout << "Pessoa adicionada com sucesso!" << std::endl;
}

void pesquisarPessoa(const Hash& hash, std::istream& input) {
    std::cout << "Digite o ID da pessoa a ser pesquisada: ";
    int id;
    input >> id;

    Pessoa pessoaEncontrada = hash.search(id);

    if (pessoaEncontrada.getId() != 0) {
        std::cout << "Pessoa encontrada: " << pessoaEncontrada.getNome() << std::endl;
    } else {
        std::cout << "Pessoa não encontrada." << std::endl;
    }
}

void removerPessoa(Hash& hash, std::istream& input) {
    std::cout << "Digite o ID da pessoa a ser removida: ";
    int id;
    input >> id;

    Pessoa pessoaRemover(id, "");
    hash.pop(pessoaRemover);
    std::cout << "Pessoa removida com sucesso!" << std::endl;
}

void verificarCheio(const Hash& hash) {
    if (hash.isFull()) {
        std::cout << "A estrutura está cheia." << std::endl;
    } else {
        std::cout << "A estrutura não está cheia." << std::endl;
    }
}

void verificarOrdemAlfabetica(HashAlfabetica& hash) {
    hash.verificarOrdemAlfabetica();
}
