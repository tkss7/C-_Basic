//526p_05.cpp
#include<iostream>
using namespace std;

template <typename T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus)
{

	T* Array = new T[sizeSrc];
	for (int i = 0; i < sizeSrc; i++)
	{
		for (int j = 0; j < sizeMinus; j++)
		{
			if (src[i] == minus[j])
				src[i] = NULL;
		}
	}
	for (int i = 0; i < sizeSrc; i++)
	{
		if (src[i])
			Array[i] = src[i];
	}
	return Array;

}

int main()
{
	int src[] = { 1,10,100,5,4 ,7 };
	int minus[] = { 1,10,100,5,4 };
	
	int* Array = remove(src, 6, minus, 5);

	for (int i = 0; Array[i];  i++)
	{
		cout << Array[i] << ' ';
	}
	delete[] Array;
}