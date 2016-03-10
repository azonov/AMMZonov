// ConsoleApplication11.cpp: определяет точку входа для консольного приложения.
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
			trans[j][i]=a[i][j];
	double det; //определитель матрицы
	//нахождение определителя для матрицы 2х2
	if (n==2)
		det=trans[1][1]*trans[2][2]-trans[1][2]*trans[2][1];
	//нахождение определителя для других матриц
	else {
		int factor=1; 
		for (int i=0;i<n;i++)
			for (int k=i+1; k<n; k++)
			{
				for (int b=i; b<n;b++)
					trans[k][b]=(-1)*trans[k][i]*trans[i][b]+trans[i][i]*trans[k][b];
				factor=factor*trans[k][i];
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
}



