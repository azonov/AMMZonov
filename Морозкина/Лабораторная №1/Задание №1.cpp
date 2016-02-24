

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
	student* stud = new student[n];

	cout << "Введите данные о студентах \n ";
	for (int i = 0; i<n; i++)
	{
		stud[i].schetchik = 0;
		cout << "   фамилия: " << "\n";
		cin >> stud[i].familia;
		cout << "   оц.мат: " << "\n";
		cin >> stud[i].ocenkamat;
		cout << "   оц.физика: " << "\n";
		cin >> stud[i].ocenkafiz;
		cout << "   оц.инф: " << "\n";
		cin >> stud[i].ocenkainf;
		if ((stud[i].ocenkamat >= 4) && (stud[i].ocenkafiz >= 4) && (stud[i].ocenkainf >= 4))
		{
			if (stud[i].ocenkamat==5)
			     stud[i].schetchik++;
			if (stud[i].ocenkafiz == 5)
		         stud[i].schetchik++;
			if (stud[i].ocenkainf == 5)
			     stud[i].schetchik++;
		}
    }
	cout << "\n";
	int k = 0;
	for (int i = 0; i<n; i++)
	{

		if (stud[i].schetchik==2)
		{
			 k++; 
			cout << stud[i].familia << " \n ";
		}
	}
	cout << "Количество студентов=" << k;
	cin.get();
	system("pause");
	return 0;
}

