//상속예시_소멸자.cpp 03/24
#include <iostream>
#include<cstring>
using namespace std;
//#include<vld.h>
class AAA
{
private:
	char* str1;
public:
	AAA(const char* s1)
	{
		str1 = new char[strlen(s1) + 1];
		strcpy(str1, s1);
	}

	virtual void showData()
	{
		cout << str1 << ", ";

	}
	virtual ~AAA() // 기본클래스 포인터가 가리키는 객체의 소멸자 호출-> 기본클래스 소멸자 호출 
	{
		cout << "~AAA()" << endl;
		delete[] str1;

	}
};

class BBB : public AAA
{
private:
	char* str2;
public:
	BBB(const char* s1, const char* s2) : AAA(s1)
	{
		str2 = new char[strlen(s2) + 1];
		strcpy(str2, s2);
	}

	void showData()
	{
		AAA::showData();
		cout << str2 << endl;

	}
	~BBB()
	{
		cout << "~BBB()" << endl;
		delete[] str2;

	}
};

int main()
{
	AAA* a1 = new BBB("Good", "morning");
	a1->showData();

	BBB* b1 = new BBB("Good", "evening"); // str2부터 지워짐 : 파생클래스부터 지워진대
	b1->showData(); // A B

	delete a1;
	delete b1;
	return 0;
}