#include <iostream>

using namespace std;

struct knot
{
    int num;
    struct knot *next;
    struct knot *prev;
};

int show_menu()
{
    char op;

    cout << "---------- MENU ----------" << endl;
    cout << "1- Inserir ao inicio lista" << endl;
    cout << "2- Inserir ao final da lista" << endl;
    cout << "3- Mostrar lista" << endl;
    cout << "4- Remover da lista" << endl;
    cout << "5- Exibir Lista - inicio -> final" << endl;
    cout << "6- Exibir Lista - final -> inicio" << endl;
    cout << "7- Sair" << endl;
    cout << "--------------------------" << endl;

    cin >> op;

    return op;
}

void insert_at_beginning(knot** head) // função de inserção está correta
{
    knot *novo = (knot *)malloc(sizeof(knot)); //alocando espaço para nova celula
    cout << "Digite um valor para inserir ao inicio da lista: " << endl;
    cin >> novo->num; // estou inserindo um valor na celula que acabei de criar
    novo->next = *head; /* quando a lista esta vazia tanto proximo quanto anterior apontam para nullptr,
    pq head e nullptr quando a lista esta vazia. já quando ha um valor na lista novo -> next aponta para
    head que era a antiga primeira celula e prev aponta para nullptr como sempre*/
    novo->prev = nullptr; // não há anterior a primeira celula - ela não aponta para nada
    if (*head != nullptr) (*head)->prev = novo;
    *head = novo;
}

void insert_at_end(knot** head)
{
    knot *novo = (knot *)malloc(sizeof(knot));
    cout << "Digite um valor para ser inserido ao final da lista: " << endl;
    cin >> novo->num;
    novo->next = nullptr; // ultimo valor da lista, nao ha proximo
    if(*head == nullptr) // se lista esta vazia aplica-se a logica de inserçao na primeira celula
    {
        novo->prev = nullptr;
        *head = novo;
        return;
    }
    knot* aux = *head; // declara um ponteiro auxiliar para percorrer a lista - pega o valor de head
    while(aux->next != nullptr) aux = aux->next; // verifica todas as celulas da lista até a achar qual tem o ponteiro next como nullptr
    aux->next = novo; // atual ultima celula passa a apontar para nova ultima celula
    novo->prev = aux; // nova celula aponta para auxiliar concluindo o duplo encadeamento
}

void remove_value()
{

}

void show_from_start(knot** head)
{
    knot* aux = *head;
    count << "nullptr <- "
    while(aux->next !=nullptr)
    {
        cout << "[" << aux->num << "] <--> ";
        aux = aux->next;
    }
    cout << ""
}

int main(int argc, char *argv[])
{

    knot *head = nullptr; // isso NÃO é um nó cabeça, estou apenas reservando um endereço de memoria

    bool is_on = true;
    char op;

    while (is_on == true)
    {
        op = show_menu();

        switch (op)
        {
        case '1':
            insert_at_beginning(&head);
            break;
        case '2':
            insert_at_end(&head);
            break;
        case '3':
            show_from_start(&head);
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
