//525p_01.cpp
#include<iostream>
using namespace std;

template <typename T>
T biggest(T *x, int size)
{
	T max = x[0];
	for (int i = 0; i < size; i++)
	{
		if (max < x[i])
			max = x[i];
	}
	return max;
}

int main()
{
	int x[5] = { 1,10,100,5,4 };
	cout << biggest(x, 5) << endl;
}