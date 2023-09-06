typedef int tipoItem;

class No
{
public:
    tipoItem valor;
    No *proximo;
};

class Fila
{
private:
    No *primeiro;
    No *ultimo;

public:
    Fila();
    ~Fila();
    bool isEmpty();
    bool isFull();
    void push(tipoItem item);
    tipoItem pop();
    void print();
};