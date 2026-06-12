#include <iostream>

using namespace std;

struct knot
{
    int num;
    struct knot *next;
};

char show_menu()
{
    char op;
    cout << "---------- MENU ----------" << endl;
    cout << "1- Inserir ao final da lista" << endl;
    cout << "2- Mostrar lista" << endl;
    cout << "3- Remover valor da lista" << endl;
    cout << "4- Sair" << endl;
    cout << "--------------------------" << endl;
    cin >> op;
    return op;
}

void insert_at_end(knot** head)
{
    knot *novo = (knot *)malloc(sizeof(knot));
    cout << "Digite um valor para ser inserido ao final da lista: " << endl;
    cin >> novo->num;
    if(*head == nullptr)
    {
        novo->next = novo;
        *head = novo;
        return;
    }
    knot *aux = *head;
    while (aux->next != *head) aux = aux -> next;
    aux->next = novo;
    novo->next = *head;
}

void show_list(knot** head)
{
    if(*head == nullptr)
    {
        cout << "A lista esta vazia!" << endl;
        return;
    }
    knot *aux = *head;
    while(aux != nullptr)
    {
        cout << "[" << aux->num << "] ";
        if (aux->next != *head)
        {
        cout << "-> ";
        aux = aux->next;
        }
        else break;
    }
    cout << endl;
}

void remove_value(knot** head)
{
    if(*head == nullptr)
    {
        cout << "A lista esta vazia!" << endl;
        return;
    }
    int val = 0;
    cout << "selecione um valor para remover da lista: ";
    cin >> val;
    cout << endl;
    knot *aux = *head;
    while(aux->num != val && aux->next != *head) aux = aux->next;
    if(aux->num != val)
    {
        cout << "Valor nao encontrado!" << endl;
        return;
    }
    if(aux == *head && aux->next == *head)
    {
        *head = nullptr;
        free(aux);
        return;
    }
    knot *prev = *head;
    while(prev->next != aux) prev = prev->next;
    prev->next = aux->next;
    if(aux == *head) *head = aux->next;
    free(aux);
}

int main(int argc, char *argv[])
{
    knot *head = nullptr;
    bool is_on = true;
    char op;
    while(is_on == true)
    {
        op = show_menu();
        switch(op)
        {
            case '1':
                insert_at_end(&head);
                break;
            case '2':
                show_list(&head);
                break;
            case '3':
                remove_value(&head);
                break;
            case '4':
                cout << "ate mais!" << endl;
                is_on = false;
                break;
            default:
                cout << "selecione uma opção valida" << endl;
                break;    
        }
    }
}