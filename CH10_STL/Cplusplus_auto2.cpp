//Cplusplus_auto2.cpp
#include<iostream>
#include<vector>
using namespace std;

int square(int n)
{
	return n * n;
}

int add(int x, int y)	//�Ű������� �����Ͻ� �Ű����� Ÿ���� �߷� �� �� �����Ƿ� auto Ű���� �Ұ�
//int add(auto x, auto y) == �Ұ���
{
	return x + y;
}

auto add(int x, double y)	 // �̷��� ���´� ����
{
	return x + y;
}

template <typename T1, typename T2>
auto ADD(T1 x, T2 y)
{
	return x + y;
}

int main()
{
	auto ret = square(3); // �Լ��� �����ϴ� ���� auto ������ ���� �� �ִ�.
	cout << "ret : " << ret << endl;

	auto sum = add(10, 20);
	cout << " sum : " << sum << endl;

	auto sum2 = add(10, 3.5);
	cout << " sum : " << sum2 << endl;

	auto t1 = ADD<int, float>(100, 1.5);

	auto t2 = ADD<int, char>(1, 'A');

	auto t3 = ADD(100, 200);

	cout << "typeid(t1).name() : " << typeid(t1).name() <<
		", " << "typeid(t2).name() : " << typeid(t2).name() <<
		", " << "typeid(t3).name() : " << typeid(t3).name() << endl;

	auto add2 = add; // add : �Լ��� => �Լ��� �ּҸ� ����Ŵ , add2 = �Լ� ������ ����
	auto sum3 = add2(100, 7.1);
	cout << "sum3 : " << sum3 << endl;

	return 0;
}