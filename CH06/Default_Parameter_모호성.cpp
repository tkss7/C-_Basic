//Default_Parameter_모호성.cpp
#include<iostream>
using namespace std;
/* 함수의 모호성(모호한 호출 1) : 아래와 같이 작성하면 function1()이 둘 중 뭘 불러야 할지 몰라서 오류가 뜸 
int function1(int n=0)
{
	return n + 1;
}
int function()
{
	return 1;
}
*/
/* 모호한 호출 3
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

	cout << function2(3.0) << endl; // double형
	cout << function2(3.0F) << endl; // float형 == double 형으로 묵시적 형변환이 일어남
	//cout << function2(3) << endl; // int형 = double 형으로 묵시적 형변환이 일어남
	// 모호한 호출 2				// int형은 float, double형 둘다 형변환이 가능하므로 형변환에 대한 !!!모호한 호출이 일어남!!!

	int a = 100, b = 200;
	cout << function3(a, b) << endl;

	return 0;
}