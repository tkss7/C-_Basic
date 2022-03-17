//method_Overloading.cpp
#include<iostream>
using namespace std;
/*
	함수 중복정의 : over loading
	return type은 오버로딩 조건에 포함되지않는다. = 리턴없이 쓰는건 가능하지만 오버로딩 함수들을 쓰고 리턴을 하면 어떤건지 알 수 없어서 오류가 뜬다.
*/
void MyFunc()
{
	cout << "MyFunc()" << endl;
}
void MyFunc(int x)
{
	cout << "MyFunc(int x) : " << x << endl;
}
void MyFunc(const char* str)
{
	cout << "MyFunc(const char *str) : " << str << endl;
}
void MyFunc(int x, double y)
{
	cout << "MyFunc(int x, double y) : " << x+y << endl;
}
void MyFunc(const char x)
{
	cout << "MyFunc(char x) : " << x << endl;
}
int main()
{
	MyFunc();
	MyFunc(100);
	MyFunc('A');
	MyFunc(100,3.5);
	MyFunc('A');
	//MyFunc(100, 200, 300);
	return 0;
}