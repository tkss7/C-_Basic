//handling02.cpp
#include<iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "두 수를 입력 : ?";
	cin >> a >> b;

	try
	{
		cout << "try block start." << endl;
		if (b == 0)
			throw b;
		
		cout << "a/b = " << a / b << endl;
		cout << "a%b = " << a % b << endl;

		cout << "try block end." << endl;
		
	}

	catch (int exp)
	{
		cout << "catch block start." << endl;

		cout << exp << " 입력. 입력오류!!" << endl;

		cout << "catch block end." << endl;
	}

	cout << "End." << endl;

	return 0;
}