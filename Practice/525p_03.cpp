//525p_03.cpp
#include<iostream>
using namespace std;

template <typename T>
void reverseArray(T* x, int size)
{
	T tmp;
	for (int i = 0; i < size / 2; i++)
	{
		int s = size - 1;
		tmp = x[i];
		x[i] = x[s - i];
		x[s - i] = tmp;
	}
}

int main()
{
	int x[] = { 1,10,100,5,4 ,7};
	int size = sizeof(x) / sizeof(x[0]);
	reverseArray(x, size);
	for (int i = 0; i < size; i++)
		cout << x[i] << ' ';
	return 0;
}