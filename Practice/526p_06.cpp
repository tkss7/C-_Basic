//526p_05.cpp
#include<iostream>
using namespace std;

template <typename T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int &retsize)
{
	retsize = sizeSrc;

	for (int i = 0; i < sizeSrc; i++)
	{
		for (int j = 0; j < sizeMinus; j++)
		{
			if (src[i] == minus[j])
			{
				src[i] = NULL;
				retsize--;
			}
		}
	}
	int count = 0;
	T* tmp = new T[retsize];
	for (int i = 0; i < sizeSrc; i++)
	{
		if (src[i]!=NULL)
			tmp[count++] = src[i];
	}
	return tmp;

}

int main()
{
	int src[] = { 1,10,100,5,4 ,7 };
	int minus[] = { 1,10,100,5,4 };
	
	int retsize;

	int* Array = remove(src, 6, minus, 5, retsize);

	for (int i = 0; i<retsize;  i++)
	{
		cout << Array[i] << ' ';
	}
	delete[] Array;
}