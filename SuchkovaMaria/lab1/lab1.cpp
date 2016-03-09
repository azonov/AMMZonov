#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
struct film {
	string title;
	int price;
	string producer;
};
bool filmsort(film a, film b)
{
    return a.price<b.price;
}
int main()
{
	int n;
	cout << "Enter the number of movies " << "\n";
	cin >> n;
	film *cartoteca = new film [n];
	for (int i=0; i<n; i++){
		cout << "Enter title " << "\n";
		cin >> cartoteca[i].title;
		cout << "Enter price " << "\n";
		cin >> cartoteca[i].price;
		cout << "Enter producer " << "\n";
		cin >> cartoteca[i].producer;
	}
	sort(cartoteca, cartoteca+n, filmsort);
	for (int i=0; i<n; i++)
		cout << cartoteca[i].title << ' ' << cartoteca[i].price << ' ' << cartoteca[i].producer << "\n";
	system ("pause");
	return 0;
}
