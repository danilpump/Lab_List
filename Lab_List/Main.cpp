#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <Windows.h>
#include <cstdlib>
#include "List.h"

using namespace std;

void changeColor(List& l);
string tmpres = "C:\\Users\\whati\\Desktop\\result.txt", tmptex = "C:\\Users\\whati\\Desktop\\text1.txt";

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	List l;


	while (1) 
	{
		system("cls");
		cout << "Создать новый список?(y/n)\n";
		char t; 
		cin >> t;
		if (t == 'n')
		{
			l.DeleteAll();
			string buffer;
			cout << "Введите имя файла:\n";
			cin >> buffer;
			l.Read(buffer);
		}
		else if (t == 'y')
			l.DeleteAll();
		else
			continue;

		boolean flag = true;
		while (flag)
		{
			system("cls");
			cout << "---------------------------------------------------------\n";
			l.Print();
			cout << "---------------------------------------------------------\n";

			cout << "Что вы хотите сделать?\n"
				<< "1) Добавить строку\n"
				<< "2) Изменить строку\n"
				<< "3) Изменить цвет\n"
				<< "4) Изменить шрифт\n"
				<< "5) Удалить строку\n"
				<< "6) Очистить список\n"
				<< "7) Сохранить в файл\n"
				<< "0) Выход\n";
			char t2;
			cin >> t2;
			switch (t2)
			{
			case '1': {
				cin.seekg(cin.eof());
				cout << "Введите строку:\n";
				string str;
				getline(cin, str);
				l.Add(str + "\n");
			}	break;
			case '2': {
				cout << "Введите номер строки:\n"
					<< "Для отмены введите 0\n";
				int n;
				cin >> n;
				if (n == 0)
					continue;
				cin.seekg(cin.eof());
				cout << "Введите строку:\n";
				string str;
				getline(cin, str);
				l.setValue(n, str + "\n");
			}	break;
			case '3': changeColor(l); break;
			case '4': {
				cout << "1) NSimSun\n"
					<< "2) Unispace\n"
					<< "3) MS Gothic\n"
					<< "4) Lucida Console\n"
					<< "5) Consolas (Стандартный)\n"
					<< "0) Выход\n";
				int n;
				cin >> n;
				if (n == 0)
					continue;
				l.changeFont(n);
			}
					break;
			case '5': {
				cout << "Введите номер строки:\n"
					<< "Для отмены введите 0\n";
				int n;
				cin >> n;
				if (n == 0)
					continue;
				l.Delete(n);
			}
				break;
			case '6': l.DeleteAll(); break;
			case '7':
			{
				string buffer;
				cout << "Введите имя сохраняемого файла:\n";
				cin >> buffer;
				l.Write(buffer);
			}	break;
			case '0': flag = false; break;
			}
		}
	}
	system("pause");
	return 0;
}

void changeColor(List& l)
{
	cout << "Введите номер строки\n";
	int n;
	cin >> n;
	cout << "Выберите цвет:\n"
		<< "1) Синий\n"
		<< "2) Зеленый\n"
		<< "3) Голубой\n"
		<< "4) Красный\n"
		<< "5) Лиловый\n"
		<< "6) Желтый\n"
		<< "7) Белый (стандартный)\n"
		<< "8) Серый\n"
		<< "9) Светло-синий\n"
		<< "0) Выход\n";
	int t;
	cin >> t;
	if ((t >= 1) && (t <= 9))
		l.setColor(n,t);
}