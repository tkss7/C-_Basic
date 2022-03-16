//ref_참조자1.cpp
#include<iostream>
using namespace std;

/*
	reference(참조자 ) : 하나의 변수를 가리키는 또하나의 이름
	주소연산자랑 다름!!!!

*/
int main()
{
	int salary = 3800000;
	// 참조자       , 참조할 변수
	int& r_salary = salary;

	cout << salary << " , " << r_salary << endl;

	r_salary += 200000;
	cout << r_salary << " , " << r_salary << endl;
	cout << &salary << " , " << &r_salary << endl; //메모리를 따로 할당받지 않다는것을 알 수 있다!!!!

	int* p1 = &salary;
	cout << *p1 << ", " << &p1 << ", " << p1 << endl;
	//int& n2 = 100; // lvalue 참조(이름이 부여된 공간)
	const int& n3 = 200; //상수로는 가능하다(불가능한 것은 아니다)

	return 0;
}