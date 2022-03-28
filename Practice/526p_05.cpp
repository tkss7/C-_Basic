//526p_05.cpp
#include<iostream>
#include<vld.h>
using namespace std;

template <typename T>
T* concat(T a[], int sizea, T b[], int sizeb)
{
	T* sum = new T[sizea + sizeb];
	int i;
	for (i = 0; i < sizea; i++)
	{
		sum[i] = a[i];
	}
	for (i = 0; i < sizeb; i++)
	{
		sum[sizea+i] = b[i];
	}
	return sum;
	

}

int main()
{
	int* cat;
	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4,7 };

	int size_x = sizeof(x) / sizeof(x[0]);
	int size_y = sizeof(y) / sizeof(y[0]);
	cat = concat(x, size_x, y, size_y);
	for (int i = 0; i<(size_x+size_y); i++)
		cout << cat[i] << ' ';

	delete[] cat;
	return 0;
}