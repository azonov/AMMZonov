// Laba2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
//#include <ctime>                                          // для функции clock

using namespace std;
void Gnome_sort(int m, int *mas)// сортировка по возрастанию
{
	int i = 1;
	while (i<m)
	{
		if (mas[i - 1] <= mas[i])
		{
			i++;
		}
		else
		{
			int t = mas[i];
			mas[i] = mas[i - 1];
			mas[i - 1] = t; //меняем местами два соседних элемента
			i--;
			if (i == 0)
			{
				i = 1;
			}
		}
	}
	cout << "Отсортированный по возрастанию массив: ";
	for (i = 0; i<m; i++) //вывод массива
		cout << mas[i] << " ";
	cout << endl;
}

void Alternative(int m, int *mas)// сортировка по убыванию
{
	int i = 0, k;
	while (i<m)
	{
		int max = mas[i];
		for (int j = i + 1; j<m; j++)
			if (mas[j]>max)
			{
				max = mas[j];
				k = j;
			}
		int t = mas[i];
		mas[i] = max;
		mas[k] = t;
		i++;
	}

	cout << "Отсортированный по убыванию массив: ";
	for (i = 0; i<m; i++) //вывод массива
		cout << mas[i] << " ";
	cout << endl;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	int n, i;
	cout << "Размер массива > "; cin >> n;
	int *a = new int[n];
	for (i = 0; i<n; i++) //ввод массива
	{
		a[i] = rand();
		cout << "a[" << i << "]=" << a[i] << endl;
	};
	Gnome_sort(n, a); //вызов гномьей сортировки   
	Alternative(n, a); //вызов сортировки по "выбору"    
	delete[]a;
	system("pause>>void");
}


