// laba1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include <iostream> 

using namespace std; 

struct students 
{ 
  char familiya[50]; 
  int inf; // ������ �� ����������� 
  int math;// o����� �� ���������� 
  int phis;//������ �� ������ 
}; 

void main() 
{ 
  setlocale(LC_ALL, "rus"); 
  int n, sch=0;
  cout<<"������� ���-�� ���������";
  cin>>n;
  students *student = new students [n]; 
  for (int i = 0; i < n; i++) 
  { 
     cout<<"������� �������"<<"\n";
	 cin>>student[i].familiya;
	 cout<<"������� ������ ��������"<<"\n";
	 cin>>student[i].inf>>student[i].math>>student[i].phis;
  }

  for (int i=0; i<n; i++)
  {
     if (student[i].inf == 5)
	 { sch = sch + 1;
	   cout<<student[i].familiya;
	 }
  }
 

  cout<<sch;

  cin.get();
  cin.get();
 
}

