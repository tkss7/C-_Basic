//key_in.cpp
#include<iostream>

/*
	using namespace std : std에 정의 된 모든 이름에 std(이름공간)을 생략하겠다.
	>> : 입력 스트림 연산자
		if (cin.fail()) // 입력받는것을 실패했다면
	{
		cin.clear();
		cin.ignore(100, '\n'); // 입력된 100바이트 안에 \n까지 비운다(지운다).
	}

*/
//using std::cout;
using namespace std; 
int main()
{
	cout << "키보드로 데이터 입력" << endl;

	int wid, hei;

	cout << "너비 : ";
	cin >> wid;	// >> : 입력 스트림 연산자

	cout << "높이 :";
	cin >> hei;

	if (cin.fail()) // 입력받는것을 실패했다면
	{
		cin.clear();
		cin.ignore(100, '\n'); // 입력된 100바이트 안에 \n까지 비운다(지운다).
	}

	int area = wid * hei;
	cout << "면적은 : " << area << endl;

	char ch;
	cout << "한문자 : ? ";
	cin >> ch;
	cout << "ch : " << ch << endl;

	return 0;
}