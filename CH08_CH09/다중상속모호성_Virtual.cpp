//���߻�Ӹ�ȣ��_Virtual.cpp
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

//�Ļ�Ŭ�������� ���Ŭ������ virtual ����� ������,
//�����Ϸ��� ���Ŭ���� ������ �ѹ� �� �Ҵ��ϰ�, �Ļ�Ŭ������ �Ҵ�� ������ �����ϵ��� �����Ѵ�.

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
class CCC : virtual public AAA // �θ�Ŭ������ �Ҵ�� ������ �ѹ��� �Ҵ��ϰ� �ڽ�Ŭ������ �Ҵ�� ������ �����Ѵ�.
{
public:
	void string3()
	{
		cout << "CCC : string3() \n";
	}
};
//string1, string2, string1, string3, showString 
//virtual ����? : //string1, string2, string3, showString �� ����
//���߻���� ���� �Ⱦ���.
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
