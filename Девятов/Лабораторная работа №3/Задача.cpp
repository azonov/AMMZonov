//�� ���� �������� ���� � ���������� �����, ���������� ��� �������, ��������� ��� � ����� ��������� ������ �����, ����������� ���������. ����������� ����������� �������� ���������� ���� ����� �� �����������. ��������� �������� � ����. 

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std; 

int fail (string buf, int number1) 
{
	int *mas = new int[number1];
	int i=0,a=0,b=1;
	mas[0]=0;

	while (i < number1)
	{
		while ((buf[i]>='0') && (buf[i]<='9'))
		{
			mas[a]=mas[a]+buf[i]*b;
			i++;
			b=b*10;
		}

		a++;
		b=1;
		
		if (buf[i]==',')
		{
			i++;
		} else
		{
			return(buf,-1);
		}
	}



	int helps;
	for (int i=0; i < number1; i++)
		for (int j=i+1; j < number1; j++)
		{
			if (mas[i]>mas[j])
			{
				helps=mas[i];
				mas[i]=mas[j];
				mas[j]=helps;
			}
		}



	ofstream fout("cpp.txt");
	for (int i=0; i< number1; i++)
	{
		fout << mas[i];
		fout << ',';
	}
	fout.close();

   return(buf, i);
	
} 



void main () 
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	char wayfile[50]; 
	cout << "������� ���� � �����: "; 
	cin >> wayfile; 

	ifstream fin(wayline); 
	int number=100;
	char buff[100]; 
	fin.getline(buff, number);

	fail (buff, number);

	if (number=-1)
	{
		cout << "���� �� ������������� �������.";
	} else
	{
		cout << "���� ������� ������";
	}

	fin.close();
	cin.get();
	cin.get();
}