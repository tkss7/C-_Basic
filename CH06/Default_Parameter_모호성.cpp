//Default_Parameter_��ȣ��.cpp
#include<iostream>
using namespace std;
/* �Լ��� ��ȣ��(��ȣ�� ȣ�� 1) : �Ʒ��� ���� �ۼ��ϸ� function1()�� �� �� �� �ҷ��� ���� ���� ������ �� 
int function1(int n=0)
{
	return n + 1;
}
int function()
{
	return 1;
}
*/
/* ��ȣ�� ȣ�� 3
int function3(int n1, int n2)
{
	return n1 + n2;
}

int function3(int &n1, int &n2)
{
	return n1 + n2;
}
*/
int function1(int n = 0)
{
	return n + 1;
}

double function2(double d = 0)
{
	cout << "function2(double d) " << endl;
	return d*3;
}

float function2(float d = 0)
{
	cout << "function2(float d) " << endl;
	return d * 2;
}

int function3(int& n1, int& n2)
{
	return n1 + n2;
}
int main()
{
	cout << function1(100) << endl;
	cout << function1() << endl;

	cout << function2(3.0) << endl; // double��
	cout << function2(3.0F) << endl; // float�� == double ������ ������ ����ȯ�� �Ͼ
	//cout << function2(3) << endl; // int�� = double ������ ������ ����ȯ�� �Ͼ
	// ��ȣ�� ȣ�� 2				// int���� float, double�� �Ѵ� ����ȯ�� �����ϹǷ� ����ȯ�� ���� !!!��ȣ�� ȣ���� �Ͼ!!!

	int a = 100, b = 200;
	cout << function3(a, b) << endl;

	return 0;
}