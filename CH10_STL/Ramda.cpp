//ramda.cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// ª�� �ڵ� , �ݹ澲�� ������ �ڵ忡�� ����.
void sum1(int x, int y)
{
	cout << "sum1() :" << x + y << endl;
}
int main()
{
	//1. �Ϲ��Լ� ȣ��
	sum1(10, 20);

	//2. �����Լ� ȣ��
	[](int x, int y)
	{
		cout << "sum1()�� ������ lamda �Լ� :" << x + y << endl;
	}(10, 30);

	//3. ���� ���ϴ� ������ �����ϴ� ����
	int sum = 0;
	[&sum](int x, int y) {sum = x + y; }(10, 30); //[ĸ��] : �ܺο� ���ǵ� ������ ����� �� ���
	cout << "sum : " << sum << endl;

	//4. for_each�� ����ϴ� ����
	vector<int>v = { 1,2,3,4,5 };
	for_each(v.begin(), v.end(), [](int n) {cout << n << ","; }); // begin(1) ���� end �ٷ�������(5) �ѹ��� ���� ������ �����Լ��� ����
	cout << endl;

	int sum2 = 0;
	for_each(v.begin(), v.end(), [&sum2](int n) {sum2 += n; }); // �ѹ��� ���ϸ� �ȴٸ� �̷������� ���ٸ� ���°� ����.
	cout << "sum2 : " << sum2 << endl;


	//5. ���ٸ�  ����ϴ� �����Լ�
	double pi = 3.14159;
	auto calc = [pi](int r)->double {return pi * r * r; };
	cout << "���� : " << calc(5) << endl;

	int num = 10, num2;
	auto f1 = [num]() {cout << num * num << endl; };
	f1();

	auto f2 = [num]()->int {return num * num; }; // �ζ��� �Լ�ȭ �� �����ϴ�. = ȣ��ο� �ٷ� �����ڵ��� ��ü�� �Ͼ��.
	cout << f2() << endl;

	auto f3 = [num, &num2]() {num2 = num * num; }; //&���� : ����� ���� ���ڴ�. , &���� : ���� ����� ����� ���� �����ϰڴ�.
	f3();
	cout << "num2 : " << num2 << endl;

	return 0;
}