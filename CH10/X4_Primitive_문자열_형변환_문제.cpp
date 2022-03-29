#include <iostream>
#include <cstring>
using namespace std;

/*
������ 03/29
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
	CMyString(const char* tmp)  //������
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
	
	operator char* () const //����ȯ ������
	{
		cout << "operator char*() const." << endl;
		return str;
	}

};

//void TestFunc(CMyString &&ref)
void TestFunc(const CMyString& ref)
{
	cout << "TestFunc(const CMyString& strParam) :" << ref << endl; // ref�� ���� �ڵ������� ����ȯ�����ڰ� �ִ��� ã�ư�
	// 1���� : operator ������, 2���� : ����ȯ ������


}

int main()
{
	//CMyString strData("Hello");

	//TestFunc(strData); //�����Լ�
	cout << "==============" << endl;
	//TestFunc(CTestData(100));
	TestFunc(CMyString("World"));

	return 0;
}

