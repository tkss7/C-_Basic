//다중상속_Intro.cpp 03/24
#include<iostream>
using namespace std;

class AAA
{
public:
	void string()
	{
		cout << "AAA : string() \n";
	}
};

class BBB
{
public:
	void string()
	{
		cout << "BBB : string() \n";
	}
};

class CCC : public AAA, public BBB //다중상속 : 득보다 실이 많다. == 잘 안씀
{
public:
	void string()
	{
		cout << "CCC : string() \n";
	}
};

int main()
{
	CCC c1;
	c1.AAA::string(); // 다중상속은 이렇게 써야한다.
	c1.BBB::string();
	c1.string();

	return 0;
}