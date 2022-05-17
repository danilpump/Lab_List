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

	int getSize() { return size; }							//Возвращает размер
	bool isEmpty() { return head == NULL; }					//Проверяет на пустоту
	Node* Head() { return head; }
	string getValue(Node* p) { return p->val; }				//Возвращает значение указанного элемента
	void setValue(Node* p, string tval) { p->val = tval; }  //Устанавливает значение указанного элемента
	void DeleteAll();								// Очистка списка
	Node* Next(Node*);							// Переход к следующему узлу
	Node* Prev(Node*);							// Переход к предыдущему
	Node* Add(string input, Node* node = NULL);	// Добавление узла списка
	void Delete(int);						// Удаление узла списка
	void Print();								// Вывод значений узлов списка
	string toString();							// Получить список в виде строки
	void Swap(Node*, Node*);					// Взаимообмен двух узлов
	void Write(string);							// Запись в файл
	void Read(string);							// Чтение с файла
	string getValue(int);
	void setValue(int, string, int color = 7);
	void setColor(int, int color = 7);
};