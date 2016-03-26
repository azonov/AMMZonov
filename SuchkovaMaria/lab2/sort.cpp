#include "stdafx.h"
#include <ctime>
void count_sort(int n, int *array, int min, int max){
	int *c = new int[max-min+1];
	for(int i = min; i <= max; ++i) c[i - min] = 0;
	for(int i = 0; i < n; ++i) ++c[array[i] - min];
	for(int i = min; i <= max; ++i)
		for(int j = c[i - min]; j--;)
			*array++ = i;
}
int main()
{
	return 0;
}

