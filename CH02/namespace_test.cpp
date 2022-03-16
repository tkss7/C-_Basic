//namespace_test.cpp

#include<iostream>
using namespace std;
namespace BestCom
{
	void showMsg(); //함수 선언문
	//C++에서는 항상 메소드를 호출하기전에 실행해야한다.
	void simpleFunc()
	{
		cout << "BestCom simpleFunc() \n";
		showMsg();
	}
	void showMsg()
	{
		cout << "BestCom Msg()() \n";
	}
}
namespace ProgCom
{
	void simpleFunc()
	{
		cout << "ProgCom simpleFunc() \n";
	}
}
/*
	:: 는 범위지정 연산자
	C++ : 보통 헤더파일 , 실행코드 , 메인메소드 총 3개로 분리한다.
*/
using namespace BestCom;
using namespace ProgCom;
int main()
{
	//simpleFunc();//네임스페이스 두개를 했기에 충돌이 난다. 이럴땐 앞에 네임스페이스명을 붙여야 한다.
	BestCom::simpleFunc();// <== 이렇게
	//BestCom::showMsg();
	showMsg();
	return 0;
}