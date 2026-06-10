#include <iostream>

using namespace std;

struct knot
{ 
    int num;
    struct knot *next;
    struct knot *prev;
};

knot *head = nullptr; // no cabeça

int show_menu()
{
    char op;

    cout << "---------- MENU ----------" << endl;
    cout << "1- Inserir ao inicio lista" << endl;
    cout << "2- Inserir ao final da lista" << endl;
    cout << "3- Inserir ao meio da lista" << endl;
    cout << "4- Remover da lista" << endl;
    cout << "5- Exibir Lista - inicio -> final" << endl;
    cout << "6- Exibir Lista - final -> inicio" << endl;
    cout << "7- Sair" << endl;
    cout << "--------------------------" << endl;

    cin >> op;

    return op;
}

void insert_at_beginning()
{
    knot *novo = (knot *)malloc(sizeof(knot)); // lembrar de fazer o cast sempre que for alocar memoria

    cout << "Digite o valor: ";
    cin >> novo->num; // numero inserido pelo usuario na struct no - variavel num -

    novo->prev = nullptr; /* exclusivamente no caso da primeira celula o ponteiro prev ira apontar para nullptr pois nao ha ninguem atras dele e o valor de head sera alterado */
    novo->next = head;

    if (head != nullptr)
    {
        head->prev = novo; // -> tem prioridade na operação portanto preciso colocar parentes no *head
    } // *head é só um ponteiro para a celula cabeça original, não estou manipulando a struct head original

    head = novo;
}

void insert_at_end()
{
    knot *novo = (knot *)malloc(sizeof(knot));

    cout << "Digite um valor: " << endl;
    cin >> novo->num;
    novo->next = nullptr;

    if(head == nullptr)
    {
        novo->prev = nullptr;
        novo->next = head;

        head = novo;
    }
    else
    {
        knot *aux = head;
        while (aux->next != nullptr)
        {
            aux = aux-> next;
        }
        aux->next = novo;
        aux->prev = ;
    }
}

void remove_value(knot **head)
{
}

void show_from_start()
{
    if (head == nullptr)
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    knot* atual = head;
    while (atual != nullptr)
    {
        cout << "[" << atual->num << "] ";
        if (atual->next != nullptr)
            cout << " ";
        atual = atual->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    bool is_on = true;
    char op;

    while (is_on == true)
    {
        op = show_menu();

        switch (op)
        {
        case '1':
            insert_at_beginning();
            break;
        case '2':
            remove_value(&head);
            break;
        case '3':
            show_from_start();
            break;
        case '4':
            cout << "Ate mais!" << endl;
            is_on = false;
            break;
        default:
            cout << "Selecione uma opcao valida!" << endl;
            break;
        }
    }
}
