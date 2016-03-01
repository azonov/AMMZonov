#include "stdafx.h" 
#include <iostream>
#include <windows.h>
using namespace std; 

struct people 
{ 
	char surname[20]; 
	int year; 
	char sex; 
}; 

int main () 
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n; 
	cout << "Введите кол-во людей: "; 
	cin >> n; 
	cout << "\n"; 

	people *p = new people [n]; 

	for (int i=0; i<n; i++) 
	{ 
		cout << "Житель № " << i+1 << "\n"; 
		cout << "Фамилия: "; 
		cin >> p[i].surname;  
		cout << "Возраст: "; 
		cin >> p[i].year; 
		cout << "Пол(м/ж): "; 
		cin >> p[i].sex; 
		cout << "\n";
	} 

	int man=0, woman=0, kman=0, kwoman=0; 

	for (int i=0; i<n; i++) { 

		if (p[i].sex='м') { 
			man=man+p[i].year; 
			kman=kman+1; 
		} else 
		{ 
			woman=woman+p[i].year; 
			kwoman=kwoman+1; 
		} 
	} 

	float eagman=0; 
	float eagwoman=0; 

	if (kman!=0) 
	{
		eagman = static_cast<float>(man)/kman; 
	}

	if (kwoman!=0)
	{
		eagwoman = static_cast<float>(woman)/kwoman; 
	}

	cout << "Житель(и), у которого(ых) возраст больше среднего: "; 

	int help=0;

	for (int i=0; i<n; i++) {

		if (p[i].sex='м') 
		{ 
			if (p[i].year > eagman) 
			{ 
				cout << p[i].surname << " "; 
				help=1;
			} 
		} else 
		{ 
			if (p[i].year > eagwoman) 
			{ 
				cout << p[i].surname << " "; 
				help=1;
			} 
		} 
	} 

	if (help==0) {
		cout << "нету.";
	}

	cin.get(); 
	cin.get(); 
}