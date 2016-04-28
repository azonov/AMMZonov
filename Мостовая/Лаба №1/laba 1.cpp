

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

struct sport {
	char surname[20];
	int mesto1;
	int mesto2;
	int mesto3;
	int mesto4;
	int mesto5;
	int sum;
};

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите кол-во участников: ";
	cin >> n;
	cout << "\n";
	sport *s=new sport[n];

	for (int i=0; i<n; i++) {
		cout << "Участник " << i+1 << "\n";
		cout << "Фамилия: ";
		cin >> s[i].surname;
		cout << "Очков за 1 соревнование: ";
		cin >> s[i].mesto1;
		cout << "Очков за 2 соревнование: ";
		cin >> s[i].mesto2;
		cout << "Очков за 3 соревнование: ";
		cin >> s[i].mesto3;
		cout << "Очков за 4 соревнование: ";
		cin >> s[i].mesto4;
		cout << "Очков за 5 соревнование: ";
		cin >> s[i].mesto5;
		cout << "\n";
	}

	for (int i=0; i<n; i++)
		s[i].sum=s[i].mesto1+s[i].mesto2+s[i].mesto3+s[i].mesto4+s[i].mesto5;

	int min=s[0].sum, kmin=0;

	for (int i=0; i<n; i++)
		if (min>s[i].sum) {
			min = s[i].sum;
			kmin = i;
		}

	cout << "Последнее место у " << s[kmin].surname;

	cin.get();
	cin.get();
}