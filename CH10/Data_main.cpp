//Data_main.cpp
#include<iostream>
#include "Data.h"
using namespace std;

int main()
{
	Data<int> d1(100); //class�� ���ø� ���� �ڷ����� �ݵ�� �Է��ؾ��Ѵ�. => ���� �Ұ�
	d1.setData(150);
	cout << "d1.setData() : " << d1.getData() << endl;

	Data<double> d2(1.5);
	//d2.setData(150);
	cout << "d2.setData() : " << d2.getData() << endl;

	Data<char> d3('A');
	//d3.setData(150);
	cout << "d3.setData() : " << d3.getData() << endl;

	return 0;
}