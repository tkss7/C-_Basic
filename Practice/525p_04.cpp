//525p_04.cpp
#include<iostream>
using namespace std;

template <typename T>
bool search(T num, T* x, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (x[i] == num)
			return true;

	}
	return false;
}

int main()
{
	int x[] = { 1,10,100,5,4 };
	int size = sizeof(x) / sizeof(x[0]);
	if (search(100, x, size))
		cout << "100�� �迭 x�� ���ԵǾ� �ִ�.";
	else
		cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�.";

	return 0;
}