//method_overloading_�����ͱ�ȯ.cpp
#include<iostream>
using namespace std;
// const�� ������ ���Ϸ� �� �� ����Ѵ�. �ذ� ���� ���� �����͸� ��ȯ, �� �����ϴ� ���̱⿡ const�� ���� �ȵȴ�.
void swap(int &ref1, int &ref2)
{
	int tmp;
	tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}
void swap(double &x, double &y)
{
	double tmp;
	tmp = x;
	x = y;
	y = tmp;
}
void swap(char& x, char& y)
{
	char tmp;
	tmp = x;
	x = y;
	y = tmp;
}
int main()
{
	int num1 = 20, num2 = 30;
	swap(num1, num2);
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(ch1, ch2);
	cout << ch1 << ' ' << ch2 << endl;

	double db11 = 1.111, db12 = 5.555;
	swap(db11, db12);
	cout << db11 << ' ' << db12 << endl;

	return 0;
}