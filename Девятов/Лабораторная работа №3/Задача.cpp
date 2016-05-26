//На вход подается путь к текстовому файлу, необходимо его открыть, Проверить что в файле находятся только числа, разделенные запятными. Реализовать рекурсивный алгоритм сортировки этих чисел по возрастанию. Результат записать в файл. 

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std; 

int fail (string buf, int *mas) 
{
	int i=buf.length()-1, a=0, b=1;

	while (i>=0)
	{
		while ((i>=0) && (buf[i]>='0') && (buf[i]<='9'))
		{
			mas[a]=mas[a]+(buf[i]-'0')*b;
			i--;
			b=b*10;
		}

		if (i<0) break;

		if (buf[i]=='-')
		{
			mas[a]=mas[a]*(-1);
			i--;
		}

		a++;
		b=1;

		if (buf[i]==',')
		{
			i--;
		} else
		{
			return 0;
		}
	}

   return a;
	
} 


void sort(int *mas, int a, int b)
{
	int first = a;
	int last = b;
	int mid;

	if (b>a)
	{
		mid=mas[(a+b)/2];
		while (first <= last)
		{
			while ((first < b) && (mas[first] < mid))
				++first;
			while ((last > a) && (mas[last] > mid))
				--last;

			if (first <= last)
			{
				int helps;
				helps = mas[first];
				mas[first]=mas[last];
				mas[last] = helps;
				++first;
				--last;
			}
		}

		if (a < last)
			sort(mas, a, last);
		if (first > b)
			sort(mas, first, b);
	}
}


void main () 
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	char wayfile[50]; 
	cout << "Введите путь к файлу: "; 
	cin >> wayfile; 

	ifstream fin(wayfile); 
    string buff;
    getline(fin, buff);


	int *mas = new int [buff.length()];
	for (int j=0; j < buff.length(); j++)
	{
		mas[j]=0;
	}


	int number = fail(buff, mas);

	if (number==0)
	{
		cout << "Файл не соответствует заданию.";
	} else
	{
		sort (mas, 0, number);

		ofstream fout("output.txt");
		
		for (int i=0; i < number+1; i++)
		{
			fout << mas[i];
			fout << ' ';
		}
		
		fout.close(); 
		cout << "Файл успешно создан.";
	}

	fin.close();
	cin.get();
	cin.get();
}