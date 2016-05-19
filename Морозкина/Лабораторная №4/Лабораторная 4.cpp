 #include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
int lev = 0, v;

struct Node //звено дерева
{
	char *str;
	Node *left, *right;
};

void add(char *newStr, Node *&p)
{
	if (p == NULL)
	{
		p = new Node;
		p->str = newStr;
		p->left = NULL;
		p->right = NULL;
	}
	else
		if (strcmp(p->str, newStr) < 0) add(newStr, p->right);
		else add(newStr, p->left);

}

void printAll(Node *&p) 
{
	if (!p) return;
	lev++;
	printAll(p->left);// вывожу левое поддерево
	for (int i = 0; i < lev; i++) cout << "-";
	cout << "”ровень:" << lev << "; Ёлемент = " << p->str << endl; // вывожу корень поддерева
	printAll(p->right);// вывожу правое поддерево
	lev--;
}

void branch(Node *&p, int m)//обхожу дерево и на m уровне считаю ветви
{
	if (!p) return;
	lev++;
	branch(p->left, m);
	if (lev == m) v++;
	branch(p->right, m);
	lev--;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int key, level;
	char buff[64];
	char* string;
	Node *root = NULL;

	cout << "¬ведите вершину дерева (строка): ";
	cin >> buff;
	string = new char[strlen(buff)];
	strcpy(string, buff);
	add(string, root);
	cout << "ƒл€ ввода звена дерева введите 1: " << endl;
	cout << "ƒл€ определени€ количество ветвей n-го уровн€ введите 2: " << endl;
	cout << "ƒл€ вывода дерева введите 3: " << endl;
	cout << "ƒл€ выхода введите 0: " << endl;
	do
	{
		cin >> key;
		if (key == 1)
		{
			cout << " «вено дерева : ";
			cin >> buff;
			string = new char[strlen(buff)];
			strcpy(string, buff);
			add(string, root);
		};
		if (key == 2)
		{
			lev = 0;
			v = 0;
			cout << "¬ведите номер уровн€ (1-начало): ";
			cin >> level;
			branch(root, level);
			cout << "количество ветвей = " << v << endl;

		}
		if (key == 3)
		{
			lev = 0;
			cout << "ƒерево: ";
			printAll(root);
		}
	} while (key != 0);
	//system("pause>>void");
}