//stack_Ǯ��.cpp
#include<iostream>

using namespace std;
int divide(int a, int b);
int main()
{
	int a, b;
input:
	cout << "�� ���� �Է� : ?";
	cin >> a >> b;

	try {
		if (b == 0)
			throw b;
		cout << "a/b = " << divide(a , b) << endl;
		cout << "a%b = " << a % b << endl;

		cout << "End." << endl;
	}
	catch (int exp)
	{
		cout << exp << " �Է�. �Է¿���!!" << endl;
		cout << "�ٽ� �Է��ϼ���" << endl;
		goto input;
	}
	catch (...) //�����ִ� catch������ ���ܻ����� ĳġ�Ͽ� ó������ �������� �����
	{
		cout << "�� �� ���� ����!!!" << endl;
	}


	return 0;
}
int divide(int a, int b) //�Լ��� ȣ���ߴµ� �����߸� �θ��Լ��� ���ϵȴ�.
{
	if (b == 0)
		throw b;
	return a / b;
}