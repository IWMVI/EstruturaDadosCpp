#include <iostream>
#include "Pilha.h"
#include <cstddef> // NULL
#include <new>

using namespace std;

Pilha::Pilha()
{
    noTopo = NULL;
}
Pilha::~Pilha()
{
    No *temp;
    while (noTopo != NULL)
    {
        temp = noTopo;
        noTopo = noTopo->proximo;
        delete temp;
    }
}
bool Pilha::isEmpty()
{
    return (noTopo == NULL);
}
bool Pilha::isFull()
{
    No *novoNo;
    try
    {
        novoNo = new No;
        delete novoNo;
        return false;
    }
    catch (bad_alloc &exception)
    {
        return true;
    }
}
void Pilha::push(tipoItem item)
{
    if (isFull())
    {
        cout << "A pilha esta cheia!\n\n";
    }
    else
    {
        No *novoNo = new No;
        novoNo->valor = item;
        novoNo->proximo = noTopo;
        noTopo = novoNo;
    }
}
tipoItem Pilha::pop()
{
    if (isEmpty())
    {
        cout << "A pilha esta vazia\n";
        return 0;
    }
    else
    {
        No *temp;
        temp = noTopo;
        tipoItem item = noTopo->valor;
        noTopo = noTopo->proximo;
        delete temp;
        return item;
    }
}
void Pilha::print()
{
    cout << "\nElemento no topo da pilha: " << noTopo -> valor << "\n";
}