//absort_ȣ��.cpp
#include<iostream>
#include<cstdlib>
using namespace std;
int divide(int a, int b);
int main()
{
	int a, b;
input:
	cout << "�� ���� �Է� : ?";
	cin >> a >> b;

	try
	{
		cout << "a/b = " << divide(a, b) << endl;
	}
	catch (char exp) // ���ܺ���� �ִ��� �ڷ����� ���� ������ abort() �Լ��� ȣ��ȴ�!!
	{
		cout << "���ܹ߻�!!" << endl;
	}

	//abort();

	cout << "End." << endl;
	



	return 0;
}
int divide(int a, int b) //�Լ��� ȣ���ߴµ� �����߸� �θ��Լ��� ���ϵȴ�.
{
	if (b == 0)
		throw b;
	return a / b;
}