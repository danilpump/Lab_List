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
		cout << "������� ����� ������?(y/n)\n";
		char t; 
		cin >> t;
		if (t == 'n')
		{
			l.DeleteAll();
			string buffer;
			cout << "������� ��� �����:\n";
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

			cout << "��� �� ������ �������?\n"
				<< "1) �������� ������\n"
				<< "2) �������� ������\n"
				<< "3) �������� ����\n"
				<< "4) �������� �����\n"
				<< "5) ������� ������\n"
				<< "6) �������� ������\n"
				<< "7) ��������� � ����\n"
				<< "0) �����\n";
			char t2;
			cin >> t2;
			switch (t2)
			{
			case '1': {
				cin.seekg(cin.eof());
				cout << "������� ������:\n";
				string str;
				getline(cin, str);
				l.Add(str + "\n");
			}	break;
			case '2': {
				cout << "������� ����� ������:\n"
					<< "��� ������ ������� 0\n";
				int n;
				cin >> n;
				if (n == 0)
					continue;
				cin.seekg(cin.eof());
				cout << "������� ������:\n";
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
					<< "5) Consolas (�����������)\n"
					<< "0) �����\n";
				int n;
				cin >> n;
				if (n == 0)
					continue;
				l.changeFont(n);
			}
					break;
			case '5': {
				cout << "������� ����� ������:\n"
					<< "��� ������ ������� 0\n";
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
				cout << "������� ��� ������������ �����:\n";
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
	cout << "������� ����� ������\n";
	int n;
	cin >> n;
	cout << "�������� ����:\n"
		<< "1) �����\n"
		<< "2) �������\n"
		<< "3) �������\n"
		<< "4) �������\n"
		<< "5) �������\n"
		<< "6) ������\n"
		<< "7) ����� (�����������)\n"
		<< "8) �����\n"
		<< "9) ������-�����\n"
		<< "0) �����\n";
	int t;
	cin >> t;
	if ((t >= 1) && (t <= 9))
		l.setColor(n,t);
}