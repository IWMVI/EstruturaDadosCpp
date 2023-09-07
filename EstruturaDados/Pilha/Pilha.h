typedef int tipoItem;

struct No
// Os nós guardam o valor atual e o endereço do próximo elemento
{
    tipoItem valor;
    No *proximo;
};

class Pilha
{
private:
    No *noTopo;

public:
    Pilha();
    ~Pilha();
    bool isEmpty();
    bool isFull();
    void push(tipoItem item);
    tipoItem pop();
    void print();
};