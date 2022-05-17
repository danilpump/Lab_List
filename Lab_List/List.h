#include <cstdio>
#include "Node.h"
using namespace std;

class List
{
	Node* head;
	Node* tail;
	int size = 0;

public:
	List() { head = NULL; tail = NULL; }

	int getSize() { return size; }							//���������� ������
	bool isEmpty() { return head == NULL; }					//��������� �� �������
	Node* Head() { return head; }
	string getValue(Node* p) { return p->val; }				//���������� �������� ���������� ��������
	void setValue(Node* p, string tval) { p->val = tval; }  //������������� �������� ���������� ��������
	void DeleteAll();								// ������� ������
	Node* Next(Node*);							// ������� � ���������� ����
	Node* Prev(Node*);							// ������� � �����������
	Node* Add(string input, Node* node = NULL);	// ���������� ���� ������
	void Delete(int);						// �������� ���� ������
	void Print();								// ����� �������� ����� ������
	string toString();							// �������� ������ � ���� ������
	void Swap(Node*, Node*);					// ����������� ���� �����
	void Write(string);							// ������ � ����
	void Read(string);							// ������ � �����
	string getValue(int);
	void setValue(int, string, int color = 7);
	void setColor(int, int color = 7);
};