#include "stdafx.h"
#include <iostream>
using namespace std;
#include <ctime>
void count(int *array, int num, int min_value, int max_value){
	clock_t start, stop;
    start = clock();        
	int *temp = new int[max_value-min_value+1];
	for(int i = min_value; i <= max_value; i++) temp[i] = 0;
	for(int i = 0; i < num; i++) temp[array[i]]++;
	int k=0;
	for(int i = min_value; i <= max_value; i++)
		for(int j = 0; j<=temp[i]; j++){
			array[k]=i;
			k++;
		}
	stop = clock();
	double time = double(stop - start) / CLOCKS_PER_SEC;
	cout<<"The result of sort in ascending order: ";
	for(int i=0; i<num; i++)
		cout<<array[i]<< " ";
	cout<<"\n"<<"Type of sort: counting sort"<<"\n";
    cout<<"Time: "<<time<<"\n";
	delete []temp;
}
void selection(int *array, int num){
	clock_t start;
    clock_t stop;
    start = clock();
	int temp;
    for(int i = 0; i < num; i++)
    { 
        int pos = i; 
        temp = array[i];
        for(int j = i + 1; j < num; ++j)
        {
            if (array[j] > temp) 
           {
               pos = j; 
               temp = array[j]; 
           }
        }
        array[pos] = array[i]; 
        array[i] = temp; 
    }
	stop = clock();
	double time = double(stop - start) / CLOCKS_PER_SEC;
	cout<<"The result of sort in descending order: ";
	for(int i=0; i<num; i++)
		cout<<array[i]<< " ";
	cout<<"\n"<<"Type of sort: selection sort"<<"\n";
    cout<<"Time: "<<time;
}
void main()
{
	int n;
	cout<<"Enter size of array"<<"\n";
	cin>>n;
	int *mas = new int [n];
	srand(time(0));
	cout<<"Random array: ";
	int min=0, max=500;
	for (int i=0; i<n; i++){
		mas[i]=rand()%(max-min+1)-min;
		cout<<mas[i]<<" ";
	}
	count(mas, n, min, max);
	selection(mas,n);
	delete[]mas;
	system ("pause");
}

