//525p_02.cpp
#include<iostream>
using namespace std;

template <typename T1, typename T2>
bool equalArrays(T1 *x, T2 *y, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (x[i] == y[i])
			count++;
		if (count == size)
			return true;
	}
	return false;
}

int main()
{
	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4 };
	if (equalArrays(x, y, 5))
		cout << "같다";
	else
		cout << "다르다";

	return 0;
}