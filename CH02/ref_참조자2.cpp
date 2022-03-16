//ref_참조자2.cpp
#include<iostream>
using namespace std;
/*
	상수를 굳이 참조자로 사용하는 이유 : 1. 메모리를 굳이 할당받지않기 위해서

	ex) 어떤 함수의 파라메터로 데이터를 넘길때 그냥 선언하면 함수의 바이트 크기만큼 또 할당을 하게 된다. 
	-> 이는 메모리의 낭비이므로 C++의 경우 참조연산자를 통해 또 할당하지 않고 메모리를 절약할 수 있다.
	-> 만약 데이터를 넘길때 함수에서 데이터의 변경을 못하게 하고 싶다면 const int &x  <== 이런식으로 하면 된다.
										
*/
//int Add1(int x, int y) { return x + y; } // 메모리를 따로 받음
int Add1(int &x, int &y) { return x + y; } // 메모리를 따로 받지 않고 참조 연산자를 사용하므로 메모리 절약 효과
int Add2(const int &x, const int &y) { return x + y; } //const를 주면 값을 변경 못함 == 변수를 바꾸고 싶지 않을때
int main()
{
	const int N = 100 + 200; //상수값을 잠깐쓰고 버리고 싶을때 굳이 메모리를 할당하지 않고 사용가능함
	const int& ref_N = 100 + 200; //임시공간을 할당하여 저장

	int n1 = 100, n2 = 200;

	int ret1 = Add1(n1, n2); // n1, n2를 따로 메모리를 할당해야함
	cout << " Add1(n1, n2) : " << ret1 << endl;

	int ret2 = Add2(100, 200);
	cout << " Add2(100, 200) : " << ret2 << endl;
	return 0;
}