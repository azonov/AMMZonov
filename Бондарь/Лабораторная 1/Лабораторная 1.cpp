#include "stdafx.h"
#include <iostream>
using namespace std;

struct section {
	char surname[100];
	int age;
	int height;
};

void main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите число человек";
	cin >> n;
	section *persona = new section[n];

	for (int i = 0; i < n; i++) {
		cout << "Фамилия: ";
		cin >> persona[i].surname;
		cout << "Возраст: ";
		cin >> persona[i].age;
		cout << "Рост: ";
		cin >> persona[i].height;
	}
	double sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum1 = sum1 + persona[i].age;
		sum2 = sum2 + persona[i].height;
	}

	for (int i = 0; i < n; i++) {
		if ((persona[i].age < (sum1 / n)) && (persona[i].height >(sum2 / n))) {
			cout << persona[i].surname;
		}
	}
	cin.get();
	cin.get();
}

