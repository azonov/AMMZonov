// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication8 - не есть читабельное название вашей лабораторной
#include "stdafx.h”//Желательно создавать пустой проект, чтобы этот хедер был не обязательным
#include <iostream>
using namespace std;//Зачем сначала подключать все пространство имен а потом отдельно cin сout, достаточно только отдельные подключения либо сразу все и то и то не имеет смысла
using std::cin;
using std::cout;
using std::endl;

#include <stdio.h>//Зачем?
#include <conio.h>//Зачем?
#include <cmath>//Зачем?
#include <string.h>//Зачем?

struct student
{
	char familia[10];//В Великобритании самую длинную фамилию носил Толлмаш-Толлмаш де Ореллана-Плантагенет-Толлмаш-Толлмаш, не будем же мы его оставлять без шансов зарегистрироваться в системе :-) 
	int ocenkamat;
	int ocenkafiz;
	int ocenkainf;
};
//Вся программа без коментариев и не включен русский текст в консоли
int main()
{
	int n, k;//не паскаль, можно k определить перед использованием
	cout << "Введите количество студентов \n “;//Разношерстность вывода, здесь \n там endl, приведите к одному стилю
	cin >> n;
	student* stud = new student[n];//чтобы не уродовать слово студент и подобные принято структуры печатать в CamelCase с большой буквы
// stud  сущ. жеребец (о мужчине); альфонс; распорка; племенной жеребец; платный любовник; пуговица; заклёпка (Thamior);
	cout << "Введите данные о студентах \n ";
	for (int i = 0; i<n; i++)
	{
		cout << "   фамилия: " << endl;
		cin >> stud[i].familia;
		cout << "   оц.мат: " << endl;
		cin >> stud[i].ocenkamat;
		cout << "   оц.физика: " << endl;
		cin >> stud[i].ocenkafiz;
		cout << "   оц.инф: " << endl;
		cin >> stud[i].ocenkainf;
		//cout << " \n “;//не нужно оставлять закоментированные строки в системах контроля версий :-)
	}
	cout << endl;
	k = 0;
	for (int i = 0; i<n; i++)
	{
//чтобы не образовывать бесконечные if переделайте на счетчик количества оценок, можно счетчик добавить в структуру студент.
		if (((stud[i].ocenkamat == 4) && (stud[i].ocenkafiz == 5) && (stud[i].ocenkainf == 5)) || ((stud[i].ocenkamat == 5) && (stud[i].ocenkafiz == 4) && (stud[i].ocenkainf == 5)) || ((stud[i].ocenkamat == 5) && (stud[i].ocenkafiz == 5) && (stud[i].ocenkainf == 4)))
		{
			k = k + 1;//k++ 
			cout << stud[i].familia << " \n ";
		}
	}
	cout << "Количество студентов=" << k;
	cin.get();
	system("pause");
	return 0;
}

