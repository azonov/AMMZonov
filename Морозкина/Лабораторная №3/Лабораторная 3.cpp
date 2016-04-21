#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
void Hanoy(int number, int m, int s1, int s2, int s3)
{
	//ofstream myfile;
	if (number != 0)
	{
		Hanoy(number - 1, m, s1, s3, s2);
		if (number == m)
		{
			ofstream myfile("d:\\hanoy.txt", ios_base::app); // открываем файл и записываем в конец файла
			cout << "\n  ѕерекладываем " << number << "-й диск с " << s1 << "-го стержн€  на " << s2 << "-й стержень";
			myfile << "\n  ѕерекладываем " << number << "-й диск с " << s1 << "-го стержн€  на " << s2 << "-й стержень";
			m = m - 1;
			myfile.close(); // закрываем файл
		}
		Hanoy(number - 1, m, s3, s2, s1);
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "¬ведите количество дисков: > "; cin >> n;
	Hanoy(n, n, 1, 3, 2);
	system("pause>>void");
}
