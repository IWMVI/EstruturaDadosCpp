#include <iostream>
#include "Pilha.h"

using namespace std;

int main()
{
    Pilha pilha;
    int opcao;
    tipoItem item;

    do
    {
        cout << "01. Empilhar elemento\n";
        cout << "02. Remover elemento\n";
        cout << "03. Imprimir pilha\n";
        cout << "00. Finalizar\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\nInforme o valor a ser inserido: ";
            cin >> item;
            pilha.push(item);
            cout << endl;
            break;

        case 2:
            item = pilha.pop();
            cout << "\nElemento removido: " << item;
            cout << "\n\n";
            break;

        case 3:
            pilha.print();
            cout << endl;
            break;

        default:
            cout << "\nOpcao invalida!\n\n";
            break;
        }
    } while (opcao != 0);
    return 0;
}
