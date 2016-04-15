// ConsoleApplication17.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string"
#include "fstream"
#include "iostream""
using namespace std;

string pr(string expression) // возвращает результат строки с числами, делениями, умножениями
{
	int zn = 0;
	for (int i = 0; i < expression.length(); i++)
	{
		if ((expression[i] == '*') || (expression[i] == '/'))
			zn++;
	}
	if (!zn)
		return expression;
	int res = 0;
	int res2 = 0;
	int i = 0;
	int izn = 0;
	while ((expression[i] >= '0') && (expression[i] <= '9'))
	{
		res = res * 10 + expression[i] - '0';
		i++;
	}
	for (int j = 0; j < zn; j++)
	{
		izn = i;
		while (i < expression.length() - 1)
		{
			i++;
			if ((expression[i] < '0') || (expression[i] > '9'))
				break;
			res2 = res2 * 10 + expression[i] - '0';
		}
		if (expression[izn] == '*')
		{
			res *= res2;
			res2 = 0;
		}
		else
		{
			res /= res2;
			res2 = 0;
		}
	}
	return to_string(res);
}
int f(string expression)
{
	string temps = "";
	int pos = 0; //позиция, с которой нужно начинать копирование
	int opens = 0; //счиает количество пар скобок
	for (int i = 0; i < expression.length(); i++) //цикл по длине строки, отправленной в функцию
	{
		if (expression[i] == '(')
		{
			if (!opens)
			{
				temps += expression.substr(pos, i - pos); //копируем символы до открытия первой найденной скобки
				pos = i + 1;
			}
			opens++;
		}
		else
			if (expression[i] == ')')
			{
				opens--;
				if (!opens)
				{
					int t = f(expression.substr(pos, i - pos)); //отправляем строку с первой найденной скобки по последнюю
					if (temps == "")
						temps += to_string(t);
					else
						if (t < 0) //вкладываем полученное число из скобки в оставшуюся строку
						{
							if (temps[temps.length() - 1] == '+')
							{
								temps[temps.length() - 1] = '-';
								temps += to_string(-t);
							}
							else
								if (temps[temps.length() - 1] == '-')
								{
									temps[temps.length() - 1] = '+';
									temps += to_string(-t);
								}
								else
									if ((temps[temps.length() - 1] == '*') || (temps[temps.length() - 1] == '/'))
									{
										int i = temps.length() - 1;
										while ((i>0)&&(temps[i] == '*') || (temps[i] == '/') || ((temps[i] >= '0') && (temps[i] <= '9')))
											i--;
										if (i == -1)
											temps = '-' + temps;
										else
											if (temps[i] == '-')
												temps[i] = '+';
											else
												temps[i] = '-';
										temps += to_string(-t);
									}
						}
						else
							temps += to_string(t);
					pos = i + 1;
				}
			}
	}
	temps += expression.substr(pos, expression.length() - pos);
	expression = temps;
	temps = "";
	pos = 0;
	string temps2 = "";
	while (pos < expression.length()) //считаем результат умножения/деления в скобках
	{
		if (((expression[pos] >= '0') && (expression[pos] <= '9')) || (expression[pos] == '*') || (expression[pos] == '/'))
		{
			temps2 += expression[pos];
		}
		else
		{
			temps += pr(temps2);
			temps2 = "";
			temps += expression[pos];
		}
		pos++;
	}
	temps += pr(temps2);
	expression = temps;
	temps = "";
	int res = 0;
	int res2 = 0;
	pos = 0;
	int pos_temp = 0;
	if (expression[0] == '-')
		pos++;
	//считаем результат сложения и вычитания
	while (((expression[pos] >= '0') && (expression[pos] <= '9'))&&(pos < expression.length()))
	{
		if ((expression[pos] >= '0') && (expression[pos] <= '9'))
			res = res * 10 + expression[pos] - '0';
		pos++;
	}
	if (expression[0] == '-')
		res = -res;
	while (pos < expression.length())
	{
		if ((expression[pos] == '+') || (expression[pos] == '-'))
		{
			pos_temp = pos;
			res2 = expression[++pos] - '0';
			while (((expression[pos] >= '0') && (expression[pos] <= '9'))&&(pos < expression.length()))
			{
				pos++;
				if ((expression[pos] >= '0') && (expression[pos] <= '9'))
					res2 = res2 * 10 + expression[pos] - '0';
			}
			if (expression[pos_temp] == '+')
				res += res2;
			else
				res -= res2;
		}
	}
	return res;
}

int main()
{
	char ch;
	ifstream fin;
	string str;
	cout<<"write the path to the file";
	cin>>str;
	fin.open("str");
	string fake = "";
	if (fin.is_open())
	{
		fin>>fake;
		int i=0, check=1;
		while ((check)&&(i<fake.length()))
		{
			if (fake[i] != (((fake[i]>='0')&&(fake[i]<='9'))||(fake[i]=='+')||(fake[i]=='-')||(fake[i]=='/')||(fake[i]=='*')))
				check=0;
			i++;

		fin.close();
		if (!check)
			cout<<"Error";
		else 
		{
			i=0;
			string expression;
			while (fake[i-1]!='\n')
			{
				expression[i]=fake[i];
				i++;
			}
			cout << f(expression);
			system("pause");
		}
		}	
	}
	else 
		cout<<"file not found";
}




