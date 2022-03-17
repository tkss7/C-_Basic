//New_동적배열_변환.cpp 03/17 O
#include<iostream>
using namespace std;
/*
	size 만큼 동적할당 후 데이터 입력하고, 동적할당 주소 변환

*/
int* NumAdd(int size)
{
	int* num = new int[size];
	int i;
	for (i = 0; i < size; i++)
	{
		cout << i << "번째 입력하시오 :";
		cin >> *(num + i);
	}

	return num;
}

int main()
{
	int size,i;

	cout << "입력할 정수의 수? ";
	cin >> size;//5

	int *Arr=NumAdd(5);
	//동적할당된 배열 출력
	cout << "배열 항목은 : ";
	for (i = 0; i < size; i++)
	{
		cout << *(Arr + i) << ", ";
	}
	cout << endl;

	delete[] Arr;
	Arr = NULL;
	return 0;
}