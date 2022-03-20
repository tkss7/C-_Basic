//Default_Paramemter1.cpp 03/17 O
//구조체는 모든게 public class => 구조체를 확장해서 만든 것 객체지향은 class로 설계해서 만드는게 바람직하다.
#include<iostream>
using namespace std;
int Add(int num1=1, int num2=1) // 디폴트 인자는 마지막에 와야한다.
{
	return num1 + num2;
}
int Sub(int num1=1, int num2=1);
//디폴트 인자 값은 반드시 선언부에만 둔다.!!
int main()
{
	cout << Add() << endl;
	cout << Add(10) << endl;
	cout << Add(10, 20) << endl;

	cout << Sub() << endl;
	cout << Sub(10) << endl;
	cout << Sub(10, 5) << endl;

	return 0;
}
int Sub(int num1, int num2)
{
	return num1 + num2;
}