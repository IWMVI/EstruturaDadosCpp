#include <iostream>
#include "Fila.h"

using namespace std;

int main()
{
    Fila fila;
    int opcao;
    tipoItem item;

    do
    {
        cout << "01. Inserir elemento\n";
        cout << "02. Remover elemento\n";
        cout << "03. Imprimir fila\n";
        cout << "00. Finalizar.\n";
        cout << "Opcao: ";

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\nInforme o valor a ser inserido: ";
            cin >> item;
            fila.push(item);
            cout << "\n";
            break;

        case 2:
            item = fila.pop();
            cout << "\nElemento removido: " << item << endl;
            cout << "\n";
            break;

        case 3:
            fila.print();
            break;

        default:
            cout << "\nOpcao invalida!\n";
            break;
        }
    } while (opcao != 0);

    return 0;
}