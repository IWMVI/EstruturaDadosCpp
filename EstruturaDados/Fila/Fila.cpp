#include <iostream>
#include "Fila.h"
#include <cstddef>
#include <new>

using namespace std;

Fila::Fila()
{
    primeiro = NULL;
    ultimo = NULL;
}
Fila::~Fila()
{
    No *temp;
    while (primeiro != NULL)
    {
        temp = primeiro;
        primeiro = primeiro->proximo;
        delete temp;
    }
    ultimo = NULL;
}
bool Fila::isEmpty()
{
    return (primeiro == NULL);
}
bool Fila::isFull()
{
    No *temp;
    try
    {
        temp = new No;
        delete temp;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}
void Fila::push(tipoItem item)
{
    if (isFull())
    {
        cout << "\nA fila esta cheia\n";
    }
    else
    {
        No *noNovo = new No;
        noNovo->valor = item;
        noNovo->proximo = NULL;
        if (primeiro == NULL)
        {
            primeiro = noNovo;
        }
        else
        {
            ultimo->proximo = noNovo;
        }
        ultimo = noNovo;
    }
}
tipoItem Fila::pop()
{
    if (isEmpty())
    {
        cout << "\nA fila esta vazia";
        return 0;
    }
    else
    {
        No *temp = primeiro;
        tipoItem item = primeiro->valor;
        primeiro = primeiro->proximo;
        if (primeiro == NULL)
        {
            ultimo = NULL;
        }

        delete temp;
        return item;
    }
}
void Fila::print()
{
    No *temp = primeiro;
    cout << "\nFila = [ ";
    while (temp != NULL)
    {
        cout << temp->valor << " ";
        temp = temp->proximo;
    }
    cout << "]\n\n";
}
