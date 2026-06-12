// Lucas Antonetti Pereira
// RA - 00887153

#include <iostream>

using namespace std;

struct cell
{
    long int num; // fibonacci cresce exponencialmente. int nao e suficiente
    struct cell *next;
};

void fibonacci(cell** head, int size)
{
    cell *aux = *head;
    for(int i = 0; i < size - 2; i++)
    {
        cell *novo = (cell *) malloc(sizeof(cell));
        novo->num = aux->num + aux->next->num; // atribui o valor de aux mais a celula a frente para a nova celula criada na iteraçao
        aux = aux->next;
        aux->next = novo;
        novo->next = nullptr;
    }
}

void show_list(cell** head)
{
    cell *aux = *head;
    while(aux != nullptr)
    {
        cout << "[" << aux->num << "]";
        if (aux->next != nullptr) cout << " -> ";
        aux = aux->next;
    }
}

int main() {
    cell *firstcell = (cell *) malloc(sizeof(cell));// não preciso cria *head = nullptr pois o primeiro e segunda valor sao fixos
    cell *secondcell = (cell *) malloc(sizeof(cell));
    firstcell->num = 0;
    secondcell->num = 1;
    firstcell->next = secondcell;
    secondcell->next = nullptr; // criando e alocando valores das duas primeiras celulas. Somente a Primeira sera entregue como parametro para a funçao
    int size = 0;
    cout << "Selecione o tamanho da lista: ";
    cin >> size;
    fibonacci(&firstcell, size);
    show_list(&firstcell);
    return 0;
}
