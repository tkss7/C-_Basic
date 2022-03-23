//Overridng_Intro.cpp
#include<iostream>
using namespace std;
/*
	�޼��� �������̵�(Overriding) : �Լ� ������(������)
	�޼��� �����ε�(Overloading) : �Լ� �ߺ�����
*/
class AAA
{
public:
	void fct()
	{
		cout << "class AAA fct()" << endl;
	}
};

class BBB : public AAA
{
public:
	void fct() //�޼��� �������̵�
	{
		cout << "class BBB fct()" << endl;
	}
};

int main()
{
	BBB b1; //�������̵��� �ڽ��� �޼��带 ȣ���Ѵ�. ���Ŭ���� �޼���� ������ ȿ��
	b1.fct();
	b1.AAA::fct(); //����� ȣ��

	BBB* b2 = new BBB;
	b2->fct();
	b2->AAA::fct(); //����� ȣ��

	AAA* a1 = b2; //Up Cast
	a1->fct(); //AAA �޼��� ȣ��		//��ü�����ʹ� �⺻������ �ڽ��� ���,�޼��常 �θ���.
	
	//a1->BBB::fct(); // Error : ���Ŭ���� �����ʹ� �Ļ�Ŭ���� ��ü�� ����ų �� ����.

	return 0;
}