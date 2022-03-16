//ref_참조자_변환.cpp
#include<iostream>
using namespace std;
/*
	
*/
int& reffuncOne(int &ref)
{
	ref++;
	return ref;
}
int reffuncTwo(int& ref)
{
	ref++;
	return ref;
}
int main()
{
	int num1 = 1;
	int& num2 = reffuncOne(num1); // 2를 받음(참조자를 반환)
	num1++;
	num2++;
	cout << num1 << ", " << num2 << endl; // 4, 4

	num1 = 1;
	int num3 = reffuncTwo(num1); //2를 받음(값을 반환)
	num1++; //2+1 = 3
	num3--; // 2-1 = 1
	cout << num1 << ", " << num3 << endl;


	return 0;
}