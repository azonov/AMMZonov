// лаба1.cpp : Defines the entry point for the console application.
//

//
//foundEngineer.cpp: oпределяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>

using namespace std;

struct workers
{
	char fname [30];
	int age;
	char specialty[30]; 
	int salary;
};

struct engineer
{
	char fnameE [30];
	int ageE;
	char specialtyE[30];
	int salaryE;
};

int main()
{
	cout<<"write count factory";
	int factory, count, count_workers=0 ; //количество фабрик, количество рабочих на фабрике,
	                                    //количество рабочих на всех фабриках
	cin>>factory;
	for (int i = 0; i < factory; i++)
	{
		cin>>count;
		count_workers=count_workers+count;
	}
	char c; //для считывания символов
	workers *work= new workers [count_workers]; 
	for (int i = 0; i < count_workers; i++)
	{
		cin.getline( work[i].fname, 30);
		cin>>work[i].age;
		cin.getline( work[i].specialty, 30);
		cin>>work[i].salary;
	}
	char eng [30] = "engineer"; count=0;
	for (int i = 0; i < count_workers; i++)
	{
		if (strcmp(work[i].fname, eng) == 0)
			count++;
	}
	engineer *engin= new engineer[count]; 
	int j=0;
	for (int i = 0; i < count_workers; i++)
	{
		if (strcmp(work[i].fname, eng) == 0)
		{
			strcpy (engin[j].fnameE, work[i].fname);
			engin[j].ageE=work[i].age;
			strcpy (engin[j].specialtyE, work[i].specialty);
			engin[j].salaryE=work[i].salary;
		}
		j++;
	}
	for (int i=0; i<j; i++)
	{
		cout<<engin[i].fnameE;
		cout<<engin[i].ageE;
		cout<<engin[i].specialtyE;
		cout<<engin[i].salaryE;
	}

	system("pause");
	return 0;
}