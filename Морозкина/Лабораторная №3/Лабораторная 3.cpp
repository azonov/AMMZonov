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
			ofstream myfile("d:\\hanoy.txt", ios_base::app); // ��������� ���� � ���������� � ����� �����
			cout << "\n  ������������� " << number << "-� ���� � " << s1 << "-�� �������  �� " << s2 << "-� ��������";
			myfile << "\n  ������������� " << number << "-� ���� � " << s1 << "-�� �������  �� " << s2 << "-� ��������";
			m = m - 1;
			myfile.close(); // ��������� ����
		}
		Hanoy(number - 1, m, s3, s2, s1);
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "������� ���������� ������: > "; cin >> n;
	Hanoy(n, n, 1, 3, 2);
	system("pause>>void");
}
