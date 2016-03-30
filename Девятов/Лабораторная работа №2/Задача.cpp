#include "stdafx.h" 
#include <iostream> 
#include <ctime> 
using namespace std; 

void fast(int *newarray, int first, int last, int m) 
{ 
	clock_t start, stop;
    start = clock();
	
	int mid, count;
	int f=first, l=last;
	mid=newarray[(f+l) / 2];
	
	do
	{
		while (newarray[f]<mid) f++;
		while (newarray[l]>mid) l--;
		if (f<=l)
		{
			count=newarray[f];
			newarray[f]=newarray[l];
			newarray[l]=count;
			f++;
			l--;
		}
	} while (f<l);
	
	if (first<l) 
	{
		fast(newarray, first, l, m);
	} 
	else 
	{
		if (f<last) 
		{
			fast(newarray, f, last, m);
		} 
		else
		{
			stop = clock();
			double time = double(stop - start) / CLOCKS_PER_SEC;
			cout << "Отсортированный массив по возрастанию: "; // Sorted array ascending
			for (int i=0; i<m; i++) 
			{ 
				cout << newarray[i] << " ";
			} 
			cout << endl << "Тип: Быстрая сортировка" << endl; // Type: Quick Sort
			cout << "Время: " << time << endl; // Time
		}
	}
} 

void selection(int *newarray, int m) 
{ 
	clock_t start, stop;
    start = clock();
	for (int i = 0; i < m; i++)
	{
		int temp = newarray[0];
		for (int j = i + 1; j < m; j++)
		{
			if (newarray[i] < newarray[j])
			{
				temp = newarray[i];
				newarray[i] = newarray[j];
				newarray[j] = temp;
			}
		}
	}
	stop = clock();
	double time = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Отсортированный массив по убыванию: "; // Sorted array Descending
	for (int i=0; i<m; i++) 
	{ 
		cout << newarray[i] << " ";
	} 
	cout << endl << "Тип: Сортировка выбором" << endl; // Type: Selection Sort
	cout << "Время: " << time << endl; // Time
} 

void main() 
{ 
	setlocale(LC_ALL, "Rus"); 
	int n, first, last;; 
	cout << "Введите кол-во элементов массива: "; // Enter the number of elements in the array
	cin >> n; 

	srand(time(NULL)); 
	
	cout << "Рандомный массив: "; // Random array
	int *array = new int [n]; 
	for (int i=0; i<n; i++) 
	{ 
		array[i] = 1 + rand() % 999;
		cout << array[i] << " ";
	} 

	cout << endl << endl;
	selection(array, n); 

	cout << endl;
	first=0; last=n-1;
	fast(array, first, last, n); 

	delete[]array; 
	cin.get(); 
	cin.get(); 
}