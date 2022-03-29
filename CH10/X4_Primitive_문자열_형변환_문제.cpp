#include <iostream>
#include <cstring>
using namespace std;

/*
실행결과 03/29
CMyString(const char * _tmp) called.
operator char*() const.
TestFunc(const CMyString& strParam) : Hello
==============
CMyString(const char * _tmp) called.
operator char*() const.
TestFunc(const CMyString& strParam) : World
~CMyString() called.
~CMyString() called.
*/
 
class CMyString
{
	char *str;
	int len;
public:
	CMyString(const char* tmp)  //생성자
	{
		cout << "CMyString(const char * _tmp) called." << endl;
		len = strlen(tmp);
		str = new char[len + 1];
		strcpy(str, tmp);
	}

	~CMyString()
	{
		cout << "~CMyString() called."<< endl;
	}

	//friend void TestFunc(const CMyString& ref);
	
	operator char* () const //형변환 연산자
	{
		cout << "operator char*() const." << endl;
		return str;
	}

};

//void TestFunc(CMyString &&ref)
void TestFunc(const CMyString& ref)
{
	cout << "TestFunc(const CMyString& strParam) :" << ref << endl; // ref만 쓰면 자동적으로 형변환연산자가 있는지 찾아감
	// 1순위 : operator 연산자, 2순위 : 형변환 연산자


}

int main()
{
	//CMyString strData("Hello");

	//TestFunc(strData); //전역함수
	cout << "==============" << endl;
	//TestFunc(CTestData(100));
	TestFunc(CMyString("World"));

	return 0;
}

