#include <iostream>
#include <Windows.h>
#include <locale>
#include <string>

using namespace std;

struct information{
  string last_name;
  int age;
  int hight;
};


void main(){
  setlocale(LC_ALL, "");
  int n, max, k, n_max;
  SetConsoleCP(866);
  cout << "Введите кол-во учащиехся : ";
  cin >> n;

  k = 0;

  information *info = new information[n];


  for( int i = 0; i < n; i++ ){
    cout << "Фамилия " << i + 1 << " члена спортивной секции : ";
    SetConsoleCP(1251);
    cin >> info[i].last_name;
    //getline(cin, info[i].last_name);
    SetConsoleCP(866);
    cout << "Возраст : ";
    cin >> info[i].age;
    cout << "Рост: ";
    cin >> info[i].hight;
    cout << endl;
  }

  max = info[0].hight;
  n_max = 0;

  for( int i = 0; i < n; i++ ){
    if( max < info[i].hight ){
      max = info[i].hight;
      n_max = i;
    }
  }

  for( int i = 0; i < n; i++ ){
    if( info[i].hight == max ){
      k++;
    }
  }

  if( k == 1 ){
    cout << "Самый высокий человек : " << info[n_max].last_name << endl;
  } else {
    if( k > 1 ){
      cout << "Самые высокие люди : " << endl;
      for( int i = 0; i < n; i++ ){
        if( info[i].hight == max ){
          cout << info[i].last_name << endl;
        }
      }
    }
  }


  system("pause");
}