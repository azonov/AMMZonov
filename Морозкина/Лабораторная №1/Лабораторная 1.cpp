#include <iostream>
using namespace std;

struct student
{
	
	char familia[100];
	int ocenkamat;
	int ocenkafiz;
	int ocenkainf;
	int schetchik;
};


int main()
{   
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество студентов \n “;
		cin >> n;
	
		student* infstud = new student[n];
		cout << "Введите данные о студентах \n ";
	for (int i = 0; i<n; i++)
	{
		infstud[i].schetchik = 0;
		cout << "   фамилия: " << "\n";
		cin >> infstud[i].familia;
		cout << "   оц.мат: " << "\n";
		cin >> infstud[i].ocenkamat;
		cout << "   оц.физика: " << "\n";
		cin >> infstud[i].ocenkafiz;
		cout << "   оц.инф: " << "\n";
		cin >> infstud[i].ocenkainf;
		}
	
	if ((infstud[i].ocenkamat >= 4) && (infstud[i].ocenkafiz >= 4) && (infstud[i].ocenkainf >= 4))
	 {
		if (infstud[i].ocenkamat == 5)
			 infstud[i].schetchik++;
		if (infstud[i].ocenkafiz == 5)
			 infstud[i].schetchik++;
		if (infstud[i].ocenkainf == 5)
			 infstud[i].schetchik++;
		}
	
}
cout << "\n";
int k = 0;
for (int i = 0; i<n; i++)
{
	if (infstud[i].schetchik == 2)
	{
		k++;
		cout << infstud[i].familia << " \n ";
	}
}

