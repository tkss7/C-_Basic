//New_�����迭_��ȯ.cpp 03/17 O
#include<iostream>
using namespace std;
/*
	size ��ŭ �����Ҵ� �� ������ �Է��ϰ�, �����Ҵ� �ּ� ��ȯ

*/
int* NumAdd(int size)
{
	int* num = new int[size];
	int i;
	for (i = 0; i < size; i++)
	{
		cout << i << "��° �Է��Ͻÿ� :";
		cin >> *(num + i);
	}

	return num;
}

int main()
{
	int size,i;

	cout << "�Է��� ������ ��? ";
	cin >> size;//5

	int *Arr=NumAdd(5);
	//�����Ҵ�� �迭 ���
	cout << "�迭 �׸��� : ";
	for (i = 0; i < size; i++)
	{
		cout << *(Arr + i) << ", ";
	}
	cout << endl;

	delete[] Arr;
	Arr = NULL;
	return 0;
}