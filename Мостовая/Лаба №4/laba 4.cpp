// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <string>

using namespace std;


//�������� ��������� Stack
struct Stack
{
	int value; //�������, ���������� � �����
 	Stack* Next; //��������� �� ��������� �������
};

//������������� Stack
//������� ����� ���������, �������� ������ �� ��������� ������� � NULL � ����������� ��������
Stack* Initialize(int x)
{
	Stack *pointer = new Stack; 
	pointer->Next = NULL; pointer->value = x;
	return pointer;
}
//���������� �������� � Stack
//������� ����� ��������� �� ���� pointer � �������������� ���, ������������ ��� ��������� Next �� ������� ����, ������������ ������������ ������� ���� pointer'�
Stack* Push(Stack* aStack,int x)
{
	Stack *pointer = Initialize(x);
	pointer->Next = aStack;
	aStack = pointer;
	return aStack;
}

//�������� �������� �� Stack
//������� ����� ��������� �� ���� pointer � �������������� ��� ������� ������, ������������� ��������� � �������� ����� �� Next, ������� pointer
Stack* Pop(Stack* aStack)
{
	Stack *pointer = aStack;
	aStack = aStack->Next;
	pointer->Next = NULL;
	delete pointer;
	return aStack;
}

//��������������� ��������� ������ ����
int print_main_menu()
{
	cout << "--------------------" << endl;
	cout << "[1] - ������������� �����" << endl;
	cout << "[2] - ���������� ��������" << endl;
	cout << "[3] - ������ �����" << endl;
	cout << "[4] - �������� ��������" << endl;
	cout << "[0] - �����" << endl;
	cout << "�������� ����� ����: ";
	int num;
	cin >> num;
	while (num < 0 || num > 4)
	{
		cout << "������! ��������� ����: ";
		cin >> num;
	}
	cout << "--------------------" << endl;
	return num;
}

//��������� �������� ����
void main_menu()
{
	int num = 1; 
	int tmp; //������������� ���������� ��� ����������/�������������
	Stack *StackForWork = NULL; //��� ����
	//���� num > 0 �� ���������� ������
	while (num > 0)
	{
		//�������� ������ ��� ����� ����
		num = print_main_menu();
		//� ����������� �� ���������� ������ ��������� ������������ ��������
		switch (num)
		{
		case 1:
		{
			cout << "������� �������, ������� ���������� ���������������� ����: " << endl;
			cin >> tmp;
			StackForWork = Initialize(tmp);
			break;
		}
		case 2: 
		{
			cout << "������� �������, ������� ���������� �������� � ����: " << endl;
			cin >> tmp;

			//���� ���� �� ���� - ������ ��������� �������, ����� - �������������� ��� ���������.
			if (StackForWork != NULL)
			{
				StackForWork = Push(StackForWork, tmp);
			}
			else
				StackForWork = Initialize(tmp);
			break;
		}
		case 3:
		{
			//������ �����������, ���� ���� �� ����
			if (StackForWork != NULL)
			{
				cout << "���� �������� ���: ";

				//������� ��������� ���� ��� ������� �� ���������
				Stack* TmpStack = StackForWork;

				//�������� ����������, ���� ��������� ���� �� ��������� � NULL
				do 
				{
					cout << " | " << TmpStack->value;
					TmpStack = TmpStack->Next;
				} while (TmpStack != NULL);
				cout << endl;

			}
			else
				cout << "��� ���� ����! ������������������ ��� ����� �������!" << endl;
			break;
		}
		case 4:
		{
			//���� ���� �� ���� - �������
			if (StackForWork != NULL)
				StackForWork = Pop(StackForWork);
			else
				cout << "������! ���������� ������� ������� �� ������� �����" << endl;
			break;
		}
		}
	}
	//������ ������
	delete StackForWork;
}

int main()
{
	//���������� ������� ������� � �������
	setlocale(LC_ALL, "Russian");
	//��������� ������� ����
	main_menu();
    return 0;
}

