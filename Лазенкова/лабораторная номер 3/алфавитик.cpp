// алфавитик.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

char APoryadok(string str, int num)
{   
	ofstream fout("ABC.txt");
	char*abc = new char[num];
	int m = 65, j = 0, i = 0, k = str.length();
	if (((int)str[i]>=65) &&((int)str[i]<=90))
	{
		while(m<90)
		{
			while(i < k)
			{
				int s = (int)str[i];
				if(s == m)
				{
					abc[j] = str[i];
					fout<<abc[j];
					cout<<abc[j];
					j++;
				    i=i+2;
				}
				else
				{
					i=i+2;
				}
				
			}
			m++;
			i=0;
		 }
	}
	else
	{
		cout<<"error";
	}

	fout.close();
	return abc[i];
}
void main()
{
	ifstream fin("symbols.txt");
	string lits;
	getline (fin, lits);
	int n=lits.length();
	if (n%2==0)
	{
		n=n/2;
	}
	else
	{
		n=n/2+1;
	}
	APoryadok(lits, n);
	fin.close();
	cin.get();
	cin.get();

}
