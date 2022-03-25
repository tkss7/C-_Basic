//handing01.cpp
#include<iostream>

using namespace std;

int main()
{
	int a, b;
input:
	cout << "두 수를 입력 : ?";
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
		cout << exp << " 입력. 입력오류!!" << endl;
		cout << "다시 입력하세요" << endl;
		goto input;
	}
	catch (...) //위에있는 catch문에서 예외사항을 캐치하여 처리하지 못했을떄 실행됨
	{
		cout << "알 수 없는 오류!!!" << endl;
	}


	return 0;
}