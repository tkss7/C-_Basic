//unHanding.cpp
#include<iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "�� ���� �Է� : ?";
	cin >> a >> b;

	if (b != 0)
	{
		cout << "a/b = " << a / b << endl;
		cout << "a%b = " << a % b << endl;
	}
	else
		cout << "0���� ���� �� �����!!" << endl;



	return 0;
}