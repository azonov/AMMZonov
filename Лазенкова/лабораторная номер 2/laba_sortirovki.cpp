// laba_sortirovki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include <iostream> 
#include <ctime> // время 

using namespace std; 

void sort_shell(int n, int *mas) // сортировка Шелла 
  { 
    int i = 0; 
    int step = n / 2;//определяем шаг сортировки 
	while (step > 0) 
	{ 
	   for (int i = 0; i < (n - step); i++) 
		{ 
			int j = i; 
			while (j <(n-step) && mas[j] > mas[j + step]) 
			{ 
				int sm = mas[j]; 
				mas[j] = mas[j + step]; 
				mas[j + step] = sm; 
				j++; 
			} 
		} 
		step = step / 2;//уменьшаем шаг 
	} 

	for (int i = 0; i < n; i++) 
    cout<<mas[i]<<' '; 
  } 
void sort_v(int n, int *mas) // Сортировка выбором 
{ 
	int i = 0, k; 
	while (i<n) 
	{ 
		int max = mas[i]; 
		for (int j = i + 1; j<n; j++) 
		if (mas[j]>max) 
		{ 
			max = mas[j]; 
			k = j; 
		} 
		int sm = mas[i]; 
		mas[i] = max; 
		mas[k] = sm; 
		i++; 
	} 
	for (i = 0; i<n; i++)
	cout<<mas[i]<<' '; 
} 
void main() 
{ 
	setlocale(LC_ALL, "Rus"); 
	clock_t start;
	clock_t stop;
	start = clock();
	int n, i; 
	cout <<"введите колличество элементов массива"; 
	cin>>n; 
	int *mas = new int[n]; 
	for (i = 0; i<n; i++) 
	{ 
		mas[i] = rand(); 
	} 
	sort_shell(n, mas); 
	sort_v(n, mas); 
	delete[]mas; 
	stop = clock();
    double time = double(stop - start) / CLOCKS_PER_SEC;
    cout<<"time :"<<time<<endl;

    cin.get();
	cin.get();

}