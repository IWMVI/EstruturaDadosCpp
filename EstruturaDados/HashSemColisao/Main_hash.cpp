#include <iostream>
#include "Hash.h"

using namespace std;

int main()
{
    Aluno aluno(0, " ");

    int tamanho, maxElementos;

    cout << "Informe o tamanho da Hash: ";
    cin >> tamanho;
    cout << "Digite o numero maximo de elementos: ";
    cin >> maxElementos;

    cout << "O fator de carga e: " << (float)maxElementos / (float)tamanho;
    cout << "\n\n";

    Hash alunoHash(tamanho, maxElementos);
    int opcao, ra;
    string nome;
    bool busca;

    do
    {
        cout << "--- MENU ---\n\n";
        cout << "01. Inserir elemento\n";
        cout << "02. Remover elemento\n";
        cout << "03. Buscar elemento\n";
        cout << "04. Imprimir\n";
        cout << "00. Finalizar\n";
        cout << "Opcao: ";
        cin >> opcao;
        cout << "\n--------------\n";

        switch (opcao)
        {

        case 0:
            cout << "\nFinalizado!\n\n";
            break;
        
        case 1:
            cout << "\nInforme o RA: ";
            cin >> ra;
            cout << "Informe o nome: ";
            cin >> nome;
            aluno = Aluno(ra, nome);
            alunoHash.push(aluno);
            cout << "\n";
            break;

        case 2:
            cout << "\nInforme o RA que sera removido: ";
            cin >> ra;
            aluno = Aluno(ra, " ");
            alunoHash.pop(aluno);
            cout << "\n";
            break;

        case 3:
            cout << "\nInforme o RA para busca: ";
            cin >> ra;
            aluno = Aluno(ra, " ");
            alunoHash.search(aluno, busca);
            cout << endl;
            if (busca)
            {
                cout << "Aluno encontrado: \n\n";
                cout << "RA: " << aluno.getRA() << "\n";
                cout << "Nome: " << aluno.getNome();
                cout << "\n\n";
            }
            else
            {
                cout << "Aluno nao encontrado.\n\n";
            }
            break;

        case 4:
            cout << "\n";
            alunoHash.print();
            cout << "\n";
            break;

        default:
            cout << "\nOpcao invalida\n\n";
            break;
        };

    } while (opcao != 0);

    return 0;
}