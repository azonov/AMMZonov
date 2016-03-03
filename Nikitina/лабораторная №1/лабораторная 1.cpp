// лабораторная 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct film
{
	char *name;
	int price;
	char producer;
};

void main ()
{
	int n

	cin >> n
	cout << "Enter the number of movies " << "\n";

	film *p= new film [n];

	for(int i=0; i<n; i++)
	{
		cout << "name:" << "\n";
		cin >> p[i].name;
		cout << "price:" << "\n";
		cin >> p[i].price;
		cout << "producer" << "\n";
		cin >> p[i].producer;
	}

	for (int i = 0; i < n-1; i++) 
	{
		for (int j = 0; j < n-1; j++)
		{
		if ( p[i].producer==p[j].producer)
			cout << p[i].name << ' ' << p[i].price;
			coot << p[j].name << ' ' << p[j].price;
		}
	}
}