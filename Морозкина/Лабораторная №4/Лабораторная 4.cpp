 #include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
int lev = 0, v;

struct Node //����� ������
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
	printAll(p->left);// ������ ����� ���������
	for (int i = 0; i < lev; i++) cout << "-";
	cout << "�������:" << lev << "; ������� = " << p->str << endl; // ������ ������ ���������
	printAll(p->right);// ������ ������ ���������
	lev--;
}

void branch(Node *&p, int m)//������ ������ � �� m ������ ������ �����
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

	cout << "������� ������� ������ (������): ";
	cin >> buff;
	string = new char[strlen(buff)];
	strcpy(string, buff);
	add(string, root);
	cout << "��� ����� ����� ������ ������� 1: " << endl;
	cout << "��� ����������� ���������� ������ n-�� ������ ������� 2: " << endl;
	cout << "��� ������ ������ ������� 3: " << endl;
	cout << "��� ������ ������� 0: " << endl;
	do
	{
		cin >> key;
		if (key == 1)
		{
			cout << " ����� ������ : ";
			cin >> buff;
			string = new char[strlen(buff)];
			strcpy(string, buff);
			add(string, root);
		};
		if (key == 2)
		{
			lev = 0;
			v = 0;
			cout << "������� ����� ������ (1-������): ";
			cin >> level;
			branch(root, level);
			cout << "���������� ������ = " << v << endl;

		}
		if (key == 3)
		{
			lev = 0;
			cout << "������: ";
			printAll(root);
		}
	} while (key != 0);
	//system("pause>>void");
}