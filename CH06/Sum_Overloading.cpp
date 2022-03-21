//Sum_Overloading.cpp
#include<vld.h>
#include<iostream>
using namespace std;

int Sum(int n1, int n2)
{
	int i,sum = 0;

	for (i = n1; i <= n2; i++)
		sum += i;
	return sum;
}
int Sum(int n1)
{
	int i, sum = 0;

	for (i = 1; i <= n1; i++)
		sum += i;
	return sum;
}
int Sum(int *n1,int n2)
{
	int i, sum = 0;

	for (i = 0; i < n2; i++)
		sum += n1[i];
	return sum;
}
int main()
{
	cout << Sum(3, 5) << endl;
	cout << Sum(3) << endl;
	cout << Sum(100) << endl;

	int num[5] = { 100,200,300,400,500 };

	cout << Sum(num, sizeof(num) / sizeof(num[0])) << endl;


	return 0;
}