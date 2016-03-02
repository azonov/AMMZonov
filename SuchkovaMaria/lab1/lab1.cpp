#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>;
struct film {
	string title;
	int price;
	string producer;
};
void main()
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
	for (int i = 0; i < n-1; i++) {
         for (int j = 0; j < n-i-1; j++) {
             if (cartoteca[j].price > cartoteca[j+1].price) {
                 int temp = cartoteca[j].price;
                 cartoteca[j].price = cartoteca[j+1].price;
                 cartoteca[j+1].price = temp;
				 string tempstr = cartoteca[j].title;
                 cartoteca[j].title = cartoteca[j+1].title;
                 cartoteca[j+1].title = temp;
				 tempstr = cartoteca[j].producer;
                 cartoteca[j].producer = cartoteca[j+1].producer;
                 cartoteca[j+1].producer = temp;
             }
         }
     }
	for (int i=0; i<n; i++)
		cout << cartoteca[i].title << ' ' << cartoteca[i].price << ' ' << cartoteca[i].producer << "\n";
	system ("pause");
}
