//다중상속모호성_Virtual.cpp
#include<iostream>
using namespace std;

class AAA
{
public:
	void string1()
	{
		cout << "AAA : string1() \n";
	}
};

//파생클래스에서 기반클래스를 virtual 상속을 받으면,
//컴파일러는 기반클래스 공간을 한번 만 할당하고, 파생클래스는 할당된 공간을 공유하도록 지시한다.

//string1,  string2
class BBB : virtual public AAA
{
public:
	void string2()
	{
		cout << "BBB : string2() \n";
	}
};

//string1,  string3
class CCC : virtual public AAA // 부모클래스가 할당된 공간을 한번만 할당하고 자식클래스가 할당된 공간은 공유한다.
{
public:
	void string3()
	{
		cout << "CCC : string3() \n";
	}
};
//string1, string2, string1, string3, showString 
//virtual 쓰면? : //string1, string2, string3, showString 만 있음
//다중상속을 거의 안쓴다.
class DDD : public BBB, public CCC
{
public:
	void showString()
	{
		cout << "DDD : showString() \n";
	}
};

int main()
{
	DDD d1;
	d1.BBB::string1();
	d1.string2();
	d1.string3();
	d1.showString();

	return 0;
}
