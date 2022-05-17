#include "List.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;

void List::DeleteAll()
{
    while(size != 0)
        Delete(1);
}

Node* List::Next(Node* node)
{
    if (isEmpty())
        return NULL;
    return node->next;
}

Node* List::Prev(Node* node)
{
    if (isEmpty())
        return NULL;
    return node->prev;
}

Node* List::Add(string input, Node* node) // Если не подавать второй аргумент, то добавление будет в верх списка
{                                                // node - текущий, elem - добавляемый
    Node* elem = new Node();
    elem->val = input;
    size++;
    if (node == NULL) // Добавление нового корня
    {
        if (head == NULL)
        {
            elem->next = NULL;
            elem->prev = NULL;
            head = elem;
            tail = elem;
        }
        else
        {
            head->next = elem;
            elem->prev = head;
            elem->next = NULL;
            head = elem;
        }
        return elem;
    }
    elem->next = node->next; // Добавление узла после текущего
    if (elem->next != NULL)
        Next(node)->prev = elem;
    node->next = elem;
    elem->prev = node;
    return elem;
}

void List::Delete(int index)
{
    int count = 1;                // Находим элемент, который хотим удалить по индексу
    Node* Del = tail;
    if (index <= size)
        while (count != index) {
            Del = Next(Del);
            count++;
        };

    Node* pv = Prev(Del);         // Заводим указатели на предыдущий удаляемому и последующий удаляемому элементы
    Node* nx = Next(Del);

    if (nx != NULL && size != 1)  // Если удаляем не голову
        nx->prev = pv;
    if (pv != NULL && size != 1)  // Если удаляем не корень
        pv->next = nx;

    if (index == size)
        head = pv;
    if (index == 1)
        tail = nx;
    size--;
    delete Del;

}

void List::Print()
{
    if (isEmpty()) { cout << "Список пуст" << endl; return; }
    Node* p = tail;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while (p != NULL) {
        SetConsoleTextAttribute(hConsole, p->color);
        cout << getValue(p);
        SetConsoleTextAttribute(hConsole, 7);
        p = Next(p);
    };
    cout << endl;
}

string List::toString()
{
    string tmp;
    if (isEmpty()) return "Список пуст";
    Node* p = tail;
    while (p != NULL) {
        tmp += getValue(p);
        p = Next(p);
    };
    return tmp;
}

void List::Swap(Node* a, Node* b)
{
    Node* tmp = new Node();
    tmp->val = a->val;
    tmp->next = a->next;
    tmp->prev = a->prev;

    a->val = b->val;
    a->next = b->next;
    a->prev = b->prev;

    b->val = tmp->val;
    b->next = tmp->next;
    b->prev = tmp->prev;
}

void List::Write(string tmpres)
{
    ofstream result(tmpres);
    if (result.is_open())
        result << this->toString();
    result.close();
}

void List::Read(string tmptex)
{
    ifstream stream(tmptex);
    char ff = '\0';
    string file_buffer;

    if (!stream.is_open())
        cout << "error openning";
    else
        while (!stream.eof())
        {
            ff = stream.get();
            file_buffer += ff;

            if (ff == '\n')
            {
                this->Add(file_buffer);
                file_buffer.clear();
            }
            if (stream.eof())
            {
                file_buffer.pop_back();
                this->Add(file_buffer);
                file_buffer.clear();
            }
        }
}

string List::getValue(int index)
{
    int count = 1;
    Node* p = tail;
    if (index <= size)
        while (count != index) {
            p = Next(p);
            count++;
        };
    return getValue(p);
}

void List::setValue(int index, string tval, int color)
{
    int count = 1;
    Node* p = tail;
    if (index <= size)
        while (count != index) {
            p = Next(p);
            count++;
        };
    p->color = color;
    p->val = tval;
}

void List::setColor(int index, int color)
{
    int count = 1;
    Node* p = tail;
    if (index <= size)
        while (count != index) {
            p = Next(p);
            count++;
        };
    p->color = color;
}