// Laba2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
//#include <ctime>                                          // ��� ������� clock

using namespace std;
void Gnome_sort(int m, int *mas)// ���������� �� �����������
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
			mas[i - 1] = t; //������ ������� ��� �������� ��������
			i--;
			if (i == 0)
			{
				i = 1;
			}
		}
	}
	cout << "��������������� �� ����������� ������: ";
	for (i = 0; i<m; i++) //����� �������
		cout << mas[i] << " ";
	cout << endl;
}

void Alternative(int m, int *mas)// ���������� �� ��������
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

	cout << "��������������� �� �������� ������: ";
	for (i = 0; i<m; i++) //����� �������
		cout << mas[i] << " ";
	cout << endl;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	int n, i;
	cout << "������ ������� > "; cin >> n;
	int *a = new int[n];
	for (i = 0; i<n; i++) //���� �������
	{
		a[i] = rand();
		cout << "a[" << i << "]=" << a[i] << endl;
	};
	Gnome_sort(n, a); //����� ������� ����������   
	Alternative(n, a); //����� ���������� �� "������"    
	delete[]a;
	system("pause>>void");
}


