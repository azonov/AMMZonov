// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <string>

using namespace std;


//Основная структура Stack
struct Stack
{
	int value; //Элемент, хранящийся в стеке
 	Stack* Next; //Указатель на следующий элемент
};

//Инициализация Stack
//Создаем новый указатель, обращаем ссылку на следующий элемент в NULL и присваиваем значение
Stack* Initialize(int x)
{
	Stack *pointer = new Stack; 
	pointer->Next = NULL; pointer->value = x;
	return pointer;
}
//Добавление элемента в Stack
//Создаем новый указатель на стек pointer и инициализируем его, перекидываем его указатель Next на текущий стек, перекидываем приравниваем текущий стек pointer'у
Stack* Push(Stack* aStack,int x)
{
	Stack *pointer = Initialize(x);
	pointer->Next = aStack;
	aStack = pointer;
	return aStack;
}

//Удаление элемента из Stack
//Создаем новый указатель на стек pointer и инициализируем его текущим стеком, перебрасываем указатель с текущего стека на Next, удаляем pointer
Stack* Pop(Stack* aStack)
{
	Stack *pointer = aStack;
	aStack = aStack->Next;
	pointer->Next = NULL;
	delete pointer;
	return aStack;
}

//Вспомогательная процедура печати меню
int print_main_menu()
{
	cout << "--------------------" << endl;
	cout << "[1] - Инициализация стека" << endl;
	cout << "[2] - Добавление элемента" << endl;
	cout << "[3] - Печать стека" << endl;
	cout << "[4] - Удаление элемента" << endl;
	cout << "[0] - Выход" << endl;
	cout << "Выберите пункт меню: ";
	int num;
	cin >> num;
	while (num < 0 || num > 4)
	{
		cout << "Ошибка! Повторите ввод: ";
		cin >> num;
	}
	cout << "--------------------" << endl;
	return num;
}

//Процедура главного меню
void main_menu()
{
	int num = 1; 
	int tmp; //целочисленная переменная для добавления/инициализации
	Stack *StackForWork = NULL; //Сам стек
	//Пока num > 0 мы продолжаем работу
	while (num > 0)
	{
		//Выбираем нужный нам пункт меню
		num = print_main_menu();
		//В зависимости от выбранного пункта выполняем определенные действия
		switch (num)
		{
		case 1:
		{
			cout << "Введите элемент, которым необходимо инициализировать стек: " << endl;
			cin >> tmp;
			StackForWork = Initialize(tmp);
			break;
		}
		case 2: 
		{
			cout << "Введите элемент, который необходимо добавить в стек: " << endl;
			cin >> tmp;

			//Если стек не пуст - просто добавляем элемент, иначе - инициализируем его элементом.
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
			//Печать выполняется, если стек не пуст
			if (StackForWork != NULL)
			{
				cout << "Стек выглядит так: ";

				//Создаем временный стек для прохода по элементам
				Stack* TmpStack = StackForWork;

				//Печатаем информацию, пока временный стек не указывает в NULL
				do 
				{
					cout << " | " << TmpStack->value;
					TmpStack = TmpStack->Next;
				} while (TmpStack != NULL);
				cout << endl;

			}
			else
				cout << "Ваш стек пуст! Проинициализируйте его перед печатью!" << endl;
			break;
		}
		case 4:
		{
			//Если стек не пуст - удаляем
			if (StackForWork != NULL)
				StackForWork = Pop(StackForWork);
			else
				cout << "Ошибка! Невозможно удалить элемент из пустого стека" << endl;
			break;
		}
		}
	}
	//Чистим память
	delete StackForWork;
}

int main()
{
	//Отображаем русские символы в консоли
	setlocale(LC_ALL, "Russian");
	//Запускаем главное меню
	main_menu();
    return 0;
}

