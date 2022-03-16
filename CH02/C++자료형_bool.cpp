//C++자료형_bool.cpp
#include<iostream>
using namespace std;
/*
	boolean : 참(1), 거짓(0)을 갖는 자료형
문제 : 정수를 입력받아 양수인지, 음수인지 출력한다.
		판단은 IsPositive() 에서 확인하여 결과는 main() 에서 출력한다.
*/

int main()
{
	bool BOOL = true;
	cout << "BOOL : " << BOOL << endl;

	BOOL = false;
	cout << "BOOL : " << BOOL << endl;

	cout << "sizeof(1) : " << sizeof(1) << endl;
	cout << "sizeof(0) : " << sizeof(0) << endl;
	cout << "sizeof(true) : " << sizeof(true) << endl;
	cout << "sizeof(false) : " << sizeof(false) << endl;

	return 0;
}