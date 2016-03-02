#include "stdafx.h"
#include <iostream>
using namespace std;
struct film {
	char title[100];
	int price;
	char producer[50];
};
void main()
{
	int n;
	cout << "Enter the number of movies " << "\n";
	cin >> n;
	film *cartoteca = new film [n];
	cout << "\n" << "Enter info about movies " << "\n";
	for (int i=0; i<n; i++){
		cin >> cartoteca[i].title;
		cin >> cartoteca[i].price;
		cin >> cartoteca[i].producer;
	}
	for (int i=0; i<n; i++)
		cout << cartoteca[i].title/* << ' ' << cartoteca[i].price << ' ' << cartoteca[i].producer*/;
	system ("pause");
}
