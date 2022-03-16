//Array_�Լ�����.cpp
#include<iostream>
using namespace std;

int Array1D(int *tmp, int size)
{
	int sum=0,i;
	for (i = 0; i < size; i++)
		sum += *(tmp + i);
	return sum;
}

//int Array2D(int (*tmp)[4], int size_r, int size_c)
int Array2D(int tmp[][4], int size_r, int size_c)
{
	int sum = 0, i, j;
	for (i = 0; i < size_r; i++)
		for (j = 0; j < size_c; j++)
			sum += *(*(tmp + i) + j);
	return sum;
}
int main()
{
	int num1[5] = { 10,20,30,40,50 }, tot, i;

	tot = Array1D(num1,sizeof(num1)/sizeof(num1[0]));
	cout << "Array1D �迭�� �� : " << tot << endl;

	int num2[2][4] = { 10,20,30,40,50,60,70,80 };
	int row = sizeof(num2) / sizeof(num2[0]);
	int col = sizeof(num2[0]) / sizeof(num2[0][0]);
	tot = Array2D(num2,row ,col);
	cout << "Array1D �迭�� �� : " << tot << endl;

	for (i = 0; i < 5; i++)
	{
		num1[i] += 1;
		cout << num1[i] << " , ";
	}
	cout << endl;

	for (auto &n : num1) //�����ڷ� n�� �����ϸ� ��ǻ� n�� num�̱� ������ num1�迭���� ������ ���� ������ �� �ִ�.
	{
		n += 1;
		cout << n << " , ";
	}
	cout << endl;

	for (i = 0; i < 5; i++)  // auto�� �迭�� ������ ������.
	{
		cout << num1[i] << " , ";
	}
	cout << endl;

	return 0;
}