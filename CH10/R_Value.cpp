//R_Value.cpp 03/29
#include<iostream>
using namespace std;

int TestFunc(int &&param) //R_value ������ : �ӽð�ü�� �����Ͽ� �����Ҽ� �ְ� ����
{
	cout << "TestFunc(int** parpam)" << param++ <<endl;
	return param;
}

int main()
{
	int x = 100;
	int& x1 = x;

	x1 = 150;
	cout << "x: " << x << ", x1: " << x1 << endl << endl;

	//int& a = 10 + 20; // �̸��� �ִ� ������ ��������
	const int& a = 10 + 20; //L_value ������

	int&& y = 10 + 20;// R_value ������
	y++;
	cout << "y : " << y << endl;

	int tmp = TestFunc(10 + 20);
	cout << "tmp: " << tmp << endl;
}