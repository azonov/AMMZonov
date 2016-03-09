// лаба1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct students 
  {
	  char familiya;
	  int inform;
	  int math;
	  int phis;
  };
	
 int main()

{ 
	setlocale (LC_ALL, "rus");
	int n, sum = 0;
    cout<<"введите число студентов";
    cin>>n;
	students student; 
    for (int i=0; i<n; i++)
    {
	   cin.getline(student[i], familiya, 20);
	   cin>>student[i].inform>>student[i].math>>student[i].phis;
	   if (student[i].inform == 5)
		  { 
			  sum = sum + 1;
			  cout<<student[i].familiya;
	       }
    }
  cout<<sum;
  return 0;
 
}

