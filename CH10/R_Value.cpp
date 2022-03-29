//R_Value.cpp 03/29
#include<iostream>
using namespace std;

int TestFunc(int &&param) //R_value 참조자 : 임시객체도 보관하여 참조할수 있게 해줌
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

	//int& a = 10 + 20; // 이름이 있는 변수만 참조가능
	const int& a = 10 + 20; //L_value 참조자

	int&& y = 10 + 20;// R_value 참조자
	y++;
	cout << "y : " << y << endl;

	int tmp = TestFunc(10 + 20);
	cout << "tmp: " << tmp << endl;
}