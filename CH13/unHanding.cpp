//unHanding.cpp
#include<iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "두 수를 입력 : ?";
	cin >> a >> b;

	if (b != 0)
	{
		cout << "a/b = " << a / b << endl;
		cout << "a%b = " << a % b << endl;
	}
	else
		cout << "0으로 나눌 수 없어요!!" << endl;



	return 0;
}