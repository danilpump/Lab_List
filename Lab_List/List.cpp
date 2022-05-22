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

Node* List::Add(string input, Node* node) // ���� �� �������� ������ ��������, �� ���������� ����� � ���� ������
{                                                // node - �������, elem - �����������
    Node* elem = new Node();
    elem->val = input;
    size++;
    if (node == NULL) // ���������� ������ �����
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
    elem->next = node->next; // ���������� ���� ����� ��������
    if (elem->next != NULL)
        Next(node)->prev = elem;
    node->next = elem;
    elem->prev = node;
    return elem;
}

void List::Delete(int index)
{
    int count = 1;                // ������� �������, ������� ����� ������� �� �������
    Node* Del = tail;
    if ((index <= size) && (index != 0))
    {
        while (count != index) {
            Del = Next(Del);
            count++;
        };
    }
    else { cout << "index <= size �� �����������\n"; return; }

    Node* pv = Prev(Del);         // ������� ��������� �� ���������� ���������� � ����������� ���������� ��������
    Node* nx = Next(Del);

    if (nx != NULL && size != 1)  // ���� ������� �� ������
        nx->prev = pv;
    if (pv != NULL && size != 1)  // ���� ������� �� ������
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
    if (isEmpty()) { cout << "������ ����" << endl; return; }
    
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
    if (isEmpty()) return "������ ����";
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
                file_buffer += "\n";
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
    {
        while (count != index) {
            p = Next(p);
            count++;
        };
    }
    else { cout << "index <= size �� �����������\n"; return ""; }
    return getValue(p);
}

void List::setValue(int index, string tval, int color)
{
    int count = 1;
    Node* p = tail;
    if (index <= size && (index != 0))
    {
        while (count != index) {
            p = Next(p);
            count++;
        };
    }
    else { cout << "index <= size �� �����������\n"; return; }
    p->color = color;
    p->val = tval;
}

void List::setColor(int index, int color)
{
    int count = 1;
    Node* p = tail;
    if ((index <= size)&&(index!=0))
    {
        while (count != index) {
            p = Next(p);
            count++;
        };
    }
    else { cout << "index <= size �� �����������\n"; return; }
    p->color = color;
}

void List::changeFont(int cFont)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    switch (cFont) 
    {
    case 1:wcscpy_s(cfi.FaceName, L"NSimSun"); break;
    case 2:wcscpy_s(cfi.FaceName, L"Unispace"); break;
    case 3:wcscpy_s(cfi.FaceName, L"MS Gothic"); break;
    case 4:wcscpy_s(cfi.FaceName, L"Lucida Console"); break;
    default:wcscpy_s(cfi.FaceName, L"Consolas"); break;
    }
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
