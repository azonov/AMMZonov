// ConsoleApplication14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double determinant (int **a, int n)
{   //создание массива для транспонирования
	int **trans = new int*[n];
	for (int i=0; i<n; i++)
		trans[i]=new int[n];
	//транспонирование массива
	for (int j=0; j<n; j++)
		for (int i=0; i<n; i++)
		{
			trans[j][i]=a[i][j];
		}
	double det; //определитель матрицы
	//нахождение определителя для матрицы 2х2
	if (n==2)
		det=trans[0][0]*trans[1][1]-trans[0][1]*trans[1][0];
	//нахождение определителя для других матриц
	else {
		int factor=1; 
		int differ;
		for (int i=0;i<n;i++)
			for (int k=i+1; k<n; k++)
			{
				differ=trans[k][i];
				trans[k][i]=(-1)*trans[k][i]*trans[i][i]+trans[i][i]*trans[k][i];
				if (trans[i][i] != 0) factor=factor*trans[i][i];
				for (int b=i+1; b<n; b++)
					trans[k][b]=(-1)*trans[i][b]*differ+trans[i][i]*trans[k][b];
			}
		int compos=1; //произведение диагольных элементов
		for (int i=0; i<n; i++)
			compos=compos*trans[i][i]; 
		det=compos/factor*1.0;
	}
	return (det);
}

int main ()
{
	cout<<"write n";
	int n;
	cin>>n;
	int **a = new int*[n];
	for (int i=0;i<n;i++)
		a[i]=new int[n];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin>>a[i][j]; 
	cout<<"determinant ="<<determinant(a,n);
	system("pause");
}