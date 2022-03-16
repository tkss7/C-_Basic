//pointer_const.cpp
#include<iostream>
using namespace std;

int main()
{
	const int PI = 3.14159; // 변수를 상수화

	int num1 = 100, num2 = 200;
	const int* p1 = &num1; //포인터가 가르키는 값을 상수화 //주로씀
	//*p1 = 150; // 불가 => 상수,포인터
	p1 = &num2; // 가능
	cout << "*p1 : " << *p1 << endl;

	int* const p2 = &num2; // 포인터가 보관중인 주소를 상수화
	*p2 = 250; //가능
	//p2 = &num1; //불가능 // 포인터, 상수
	cout << "*p2 : " << *p2 << endl;

	const int* const p3 = &num1;
	//p3 = &num2; //불가
	//*p3 = 150; //불가

	return 0;
}