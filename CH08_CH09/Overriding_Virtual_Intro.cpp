//Overriding_Virtual_Intro.cpp 03/24
#include<iostream>
using namespace std;
/*
	virtual�� ��ӵȴ�. = �θ�Ŭ�����ʿ��� �൵ ������ �������� ���� �������� �� �ش�.
	����ÿ� �ٲ�°�
*/
class AAA
{
public:
	virtual void fct()
	{
		cout << "class AAA fct()" << endl;
	}
};

class BBB : public AAA // ��ӹ޴� �ڽ�Ŭ������ �����Լ���
{
public:
	virtual void fct() //�޼��� �������̵�
	{
		cout << "class BBB fct()" << endl;
	}
};

class CCC : public BBB
{
public:
	virtual void fct() //�޼��� �������̵�
	{
		cout << "class CCC fct()" << endl;
	}
};

int main()
{
	BBB* b1 = new BBB;
	b1->fct(); // BBB
	b1->AAA::fct(); // AAA
	cout << "==========================================" << endl;

	//���Ŭ���� �����Ͱ� �Ļ�Ŭ���� �޼��带 ȣ���Ѵ�.
	//����� ���Ŭ������ ������(�� ����� �Ļ�Ŭ���� �ּҺ���, ��������)
	// �Լ��� virtual�� �Ǹ� ��ü������ Ÿ�԰� �������, ����Ű�� ��� ��ü�� ������ �ȴ�.
	AAA* a1 = new BBB;
	a1->fct(); // AAA , virtual => BBB

	AAA* a2 = new CCC;
	a2->fct(); // CCC

	BBB* b2 = new CCC;
	b2->fct(); // CCC
cout << "============================================" << endl;

	AAA* a3 = b2;
	a3->fct(); // CCC
	a3->AAA::fct(); // AAA
	//a3->CCC::fct();
	//a3->BBB::fct();
	
	AAA* a4 = new AAA;
	//CCC* c1 = a4; // Down Cast
	return 0;
}