// лаба1.cpp : Defines the entry point for the console application.
//

// ConsoleApplication9.cpp: определяет точку входа для консольного приложения.
//

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
	workers *a= new workers [count_workers];
	for (int i = 0; i < count_workers; i++)
	{
		cin.getline( a[i].fname, 30);
		cin>>a[i].age;
		cin.getline( a[i].specialty, 30);
		cin>>a[i].salary;
	}
	char eng [30] = "engineer"; count=0;
	for (int i = 0; i < count_workers; i++)
	{
		if (strcmp(a[i].fname, eng) == 0)
			count++
	}
	engineer *b= new engineer[count];
	int j=0;
	for (int i = 0; i < count_workers; i++)
	{
		if (strcmp(a[i].fname, eng) == 0)
		{
			strcpy (b[j].fnameE, a[i].fname);
			b[j].ageE=a[i].age;
			strcpy (b[j].specialtyE, a[i].specialty);
			b[j].salaryE=a[i].salary;
		}
		j++;
	}
	for (int i=0; i<j; i++)
	{
		cout<<b[i].fnameE;
		cout<<b[i].ageE;
		cout<<b[i].specialtyE;
		cout<<b[i].salaryE;
	}

	system("pause");
}