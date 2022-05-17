#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <Windows.h>
#include <cstdlib>
#include "List.h"

using namespace std;

void write(List test);
void readFile(List& l);
string tmpres = "C:\\Users\\whati\\Desktop\\result.txt", tmptex = "C:\\Users\\whati\\Desktop\\text2.txt";

int main() {
	setlocale(LC_ALL, "Russian");
	string buffer;
	List l;

	l.Read(tmptex);
	l.Print();
	l.Write(tmpres);


	l.setColor(1, 1);  // Меняем цвета первых пяти строк, а в пятую еще и делаем свою запись
	l.setColor(2, 2);
	l.setColor(3, 3);
	l.setColor(4, 4);
	l.setValue(5, "5 line\n", 5);

	l.Print();
	//l.DeleteAll();
	l.Delete(4);
	l.Print();

	system("pause");
	return 0;
}

void write(List l)
{
	ofstream result(tmpres);
	if (result.is_open())
		result << l.toString();
	result.close();
}

void readFile(List& l)
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
				l.Add(file_buffer);
				file_buffer.clear();
			}
			if (stream.eof())
			{
				file_buffer.pop_back();
				l.Add(file_buffer);
				file_buffer.clear();
			}
		}
}