//Template_다중자료형.cpp
#include<iostream>
using namespace std;

template <typename T1, typename T2>
void mcopy(T1 *sour, T2 dest[], int size)
{
	for (int i = 0; i < size; i++)
		dest[i] = (T2)sour[i];
}

int main()
{
	int x[] = { 1,2,3,4,5 };
	double d[5];

	mcopy(x, d, 5); //배열복사
	for (int i = 0; i < 5; i++)
		cout << d[i] << ", ";
	cout << endl;

	char c1[5] = { 'A','B','C','D','E' }, c2[5];

	mcopy(c1, c2, 5); //배열복사
	for (int i = 0; i < 5; i++)
		cout << c2[i] << ", ";
	cout << endl;


}