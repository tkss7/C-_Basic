//Default_Paramemter1.cpp 03/17 O
//����ü�� ���� public class => ����ü�� Ȯ���ؼ� ���� �� ��ü������ class�� �����ؼ� ����°� �ٶ����ϴ�.
#include<iostream>
using namespace std;
int Add(int num1=1, int num2=1) // ����Ʈ ���ڴ� �������� �;��Ѵ�.
{
	return num1 + num2;
}
int Sub(int num1=1, int num2=1);
//����Ʈ ���� ���� �ݵ�� ����ο��� �д�.!!
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