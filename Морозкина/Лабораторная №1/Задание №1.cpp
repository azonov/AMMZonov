// ConsoleApplication8.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <string.h>

struct student
{
	char familia[10];
	int ocenkamat;
	int ocenkafiz;
	int ocenkainf;
};

int main()
{
	int n, k;
	cout << "������� ���������� ��������� \n ";
	cin >> n;
	student* stud = new student[n];
	cout << "������� ������ � ��������� \n ";
	for (int i = 0; i<n; i++)
	{
		cout << "   �������: " << endl;
		cin >> stud[i].familia;
		cout << "   ��.���: " << endl;
		cin >> stud[i].ocenkamat;
		cout << "   ��.������: " << endl;
		cin >> stud[i].ocenkafiz;
		cout << "   ��.���: " << endl;
		cin >> stud[i].ocenkainf;
		//cout << " \n ";
	}
	cout << endl;
	k = 0;
	for (int i = 0; i<n; i++)
	{
		if (((stud[i].ocenkamat == 4) && (stud[i].ocenkafiz == 5) && (stud[i].ocenkainf == 5)) || ((stud[i].ocenkamat == 5) && (stud[i].ocenkafiz == 4) && (stud[i].ocenkainf == 5)) || ((stud[i].ocenkamat == 5) && (stud[i].ocenkafiz == 5) && (stud[i].ocenkainf == 4)))
		{
			k = k + 1;
			cout << stud[i].familia << " \n ";
		}
	}
	cout << "���������� ���������=" << k;
	cin.get();
	system("pause");
	return 0;
}

