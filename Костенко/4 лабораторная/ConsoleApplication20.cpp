// ConsoleApplication20.cpp: определ€ет точку входа дл€ консольного приложени€.
//

// ConsoleApplication20.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct numbers
{
	int x;
	numbers *next;
};

void push (numbers *&next, int x) //добавл€ет символы в стек
{
	numbers *temp=new numbers;
	temp->x = x;
	temp->next =next;
	next=temp;
}

int pop (numbers *&next, bool check, int count) //печатает символы из стека 
{
	int temp = next->x;
	numbers *tempStack = next;
	next= next->next;
	if (check==1)
		cout<<"+"<<temp<<"\n";
	else 
		cout<<"-"<<temp<<" count in stack: "<<count-1<<"\n";
	delete tempStack;
	return temp;

}

int main ()
{
	numbers *p = new numbers;
	p->next = NULL;
	const int n = 255;
	char *str = new char[n + 1];
	cin.get(str,n+1);
	int count=0;
	bool check=0;
	int i=0;
	while ( str[i] != '.') //считывание
	{
		int x=0; 
		while ((str[i] != ' ')&&(str[i] != '.')) //формируем число
		{
			if (check==0){
				x=str[i]-48;
				check=1;
			}
			else 
				x=x*10+(str[i]-48);
			i++;
		}
		if (str[i-1] != ' ') count++;
		if (((str[i] == '.')&&(str[i-1] !='.')&&(str[i-1] != ' '))||(str[i] != '.'))
		{
			if (str[i] != '.') i++;
			check=0;
			push(p, x);
		}
	}
	check=1;
	int countNumber=count;
	for (int i=0; i<countNumber; i++)
	{
		pop(p,check,count);
		count--;
		if (check) check=0;
		else if (!check) check=1;
	}
	delete []str;
	system ("pause");
}

