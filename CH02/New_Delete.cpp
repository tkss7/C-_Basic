//New_Delete.cpp 03/17 O
#include<iostream>
using namespace std;

int main()
{
	int* num = new int;
	int *N = new int(200); //4바이트에 200 넣고 초기화할께요.
	char* str = new char[20];
	int* Array = new int[5];

	*num = 100;
	strcpy(str, "Hello World.");
	*(Array + 0) = 10;
	*(Array + 1) = 20;

	cout << *num << endl;
	cout << N << endl;
	cout << str << endl;
	cout << Array[0] <<", "<<Array[1]<< endl;
	cout << Array[2] << ", " << Array[3] << endl;

	delete num;
	delete N;
	delete[] Array;
	delete[] str;

	num = NULL;
	N = NULL;
	Array= NULL;
	str = nullptr; // null pointer

	return 0;
}