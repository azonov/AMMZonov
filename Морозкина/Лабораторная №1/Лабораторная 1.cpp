#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;

struct student
{
	
	char familia[100];
	int ocenkamat;
	int ocenkafiz;
	int ocenkainf;
	int schetchik;
};


int main()
{   
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "¬ведите кол-во студентов: \n ";
		cin >> n;
	
		student* infstud = new student[n];
		cout << "¬ведите данные о студентах: \n ";
	for (int i = 0; i<n; i++)
	{
		infstud[i].schetchik = 0;
		cout << "‘амили€: " << "\n";
		cin >> infstud[i].familia;
		cout << "ќцента по мат.: " << "\n";
		cin >> infstud[i].ocenkamat;
		cout << "ќценка по физике: " << "\n";
		cin >> infstud[i].ocenkafiz;
		cout << "ќценка по информатике: " << "\n";
		cin >> infstud[i].ocenkainf;
		}
	for (int i=0; i<n; i++)
	{
	if ((infstud[i].ocenkamat >= 4) && (infstud[i].ocenkafiz >= 4) && (infstud[i].ocenkainf >= 4))
	 {
		if (infstud[i].ocenkamat == 5)
			 infstud[i].schetchik++;
		if (infstud[i].ocenkafiz == 5)
			 infstud[i].schetchik++;
		if (infstud[i].ocenkainf == 5)
			 infstud[i].schetchik++;
		}
	}
cout << "\n";
int k = 0;
for (int i = 0; i<n; i++)
{
	if (infstud[i].schetchik == 2)
	{
		k++;
		cout << infstud[i].familia << " \n ";
	}
}

cin.get();
cin.get();

}