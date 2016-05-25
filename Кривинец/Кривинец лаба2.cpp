#include <stdio.h>
#include <iostream>
#include <locale>
#include <ctime>
#include <Windows.h>

using namespace std;
/*                                                     Пирамида                                         */
void swap (int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void piramide ( int *a, int n ){
  int i, sh, b, time_start;
  time_start = clock();
  sh = 0;
  b = 0;

  while (1){
    b = 0;
    for (i = 0; i < n; ++i)
    {
      if (i * 2 + 2 + sh < n)
      {
        if (a[i + sh] > a[i * 2 + 1 + sh] || a[i + sh] > a[i * 2 + 2 + sh]){
	        if (a[i * 2 + 1 + sh] < a[i * 2 + 2 + sh])
	      {
	        swap (a[i + sh], a[i * 2 + 1 + sh]);
	        b = 1;
	      }
	        else if (a[i * 2 + 2 + sh] < a[i * 2 + 1 + sh]){
	        swap (a[i + sh],a[i * 2 + 2 + sh]);
	        b = 1;
	        }
	      }
      }
      else if (i * 2 + 1 + sh < n)
      {
        if (a[ i + sh] > a[i * 2 + 1 + sh]){
	        swap (a[ i + sh], a[i * 2 + 1 + sh]);
	        b = 1;
	      }
      }
    }
    if (!b) sh++;
    if (sh + 2 == n)
      break;
  }

  for (i = 0; i < n; ++i){
    cout << a[i] << " ";
  }

  cout << endl << "Пирамидная сортировка занимает : " << clock() - time_start << "мкс" << endl;
}

/*                                                     Вставка                                         */

void vstavka_1 (int *c, int n){
  int t, i, j, time_start;

  time_start = clock();

  for (i = n - 1; i >= 0; i--){
    t = c[i];
    for (j = i; j >= 0 && c[j + 1] > t; j++){
      c[j] = c[j + 1];
    }
    c[j] = t;
  }
  for (i = 1; i < n; i++){
    cout << c[i] << " ";
  }


  cout << endl << "Cортировка вставками занимает : " << clock() - time_start << "мкс" << endl;
}

void vstavka_2 (int *f, int n){
  int t, i, j, time_start;

  time_start = clock();

  for (i = 1; i < n; i++){
    t = f[i];
    for (j = i; j > 0 && f[j - 1] > t; j--){
      f[j] = f[j - 1];
    }
    f[j] = t;
  }

  for (i = 0; i < n; i++){
    cout << f[i] << " ";
  }


  cout << endl << "Cортировка вставками занимает : " << clock() - time_start << "мкс" << endl;
}


void main(){
  setlocale(LC_ALL, "");
  srand(time(NULL));
  int n, i, time_start, time_end;

  cout << "Введите размерности массивов : ";
  cin >> n;
  
  int *a = new int[n];
  int *c = new int[n];
  int *f = new int[n];

  cout << "---------------------------------------------------" << endl;
  cout << "Первый массив : " << endl;

  for ( i = 0; i < n; i++ ){
    a[i] = rand() % n;
    cout << a[i] << " ";
  }

  cout << endl;

  cout << "---------------------------------------------------" << endl;
  cout << "Второй массив : " << endl;

  for ( i = 0; i < n; i++ ){
    c[i] = rand() % n;
    cout << c[i] << " ";
  }

  cout << endl;

  cout << "---------------------------------------------------" << endl;
  cout << "Третий массив : " << endl;

  for ( i = 0; i < n; i++ ){
    f[i] = rand() % n;
    cout << f[i] << " ";
  }

  cout << endl;

  cout << "---------------------------------------------------" << endl;
  cout << "Первый массив : " << endl;
  piramide( a, n );

  cout << "---------------------------------------------------" << endl;
  cout << "Второй массив : " << endl;
  vstavka_1( c, n );

  cout << "---------------------------------------------------" << endl;
  cout << "Третий массив : " << endl;
  vstavka_2( f, n );


  cout << endl;
  system("pause");
}