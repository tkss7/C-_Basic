//method_Overloading.cpp
#include<iostream>
using namespace std;
/*
	�Լ� �ߺ����� : over loading
	return type�� �����ε� ���ǿ� ���Ե����ʴ´�. = ���Ͼ��� ���°� ���������� �����ε� �Լ����� ���� ������ �ϸ� ����� �� �� ��� ������ ���.
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