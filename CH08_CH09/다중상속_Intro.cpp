//���߻��_Intro.cpp 03/24
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

class CCC : public AAA, public BBB //���߻�� : �溸�� ���� ����. == �� �Ⱦ�
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
	c1.AAA::string(); // ���߻���� �̷��� ����Ѵ�.
	c1.BBB::string();
	c1.string();

	return 0;
}