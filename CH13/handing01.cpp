//handing01.cpp
#include<iostream>

using namespace std;

int main()
{
	int a, b;
input:
	cout << "�� ���� �Է� : ?";
	cin >> a >> b;

	try {
		if (b == 0)
			throw b;
		cout << "a/b = " << a / b << endl;
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