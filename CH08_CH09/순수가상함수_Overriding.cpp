//���������Լ�_Overriding.cpp 03/24
#include<iostream>
using namespace std;
/*
	virtual�� ��ӵȴ�. = �θ�Ŭ�����ʿ��� �൵ ������ �������� ���� �������� �� �ش�.
	����ÿ� �ٲ�°�
*/
class AAA
{
public:
	virtual void fct() = 0; // ���� �����Լ� : ����ΰ� ����
	void show()
	{
		cout << "AAA show()" << endl;
	}

};

class BBB : public AAA
{
public:
	virtual void fct() // �Ļ� Ŭ������ �ݵ�� ���� �����Լ� �����ؾ� �Ѵ�.
	{ // virtual�� ��ӵǹǷ� �ڽ�Ŭ�������� �Ƚᵵ �ȴ�.
		cout << "class BBB fct()" << endl;
	}
};

class CCC : public BBB
{
public:
	virtual void fct()  // �Ļ� Ŭ������ �ݵ�� ���� �����Լ� �����ؾ� �Ѵ�.
	{
		cout << "class CCC fct()" << endl;
	}
};

int main()
{
	//AAA* a1 = new AAA; //�߻� Ŭ������ ��ü�� ������ �� ����.

	AAA* a2 = new BBB();
	a2->fct(); //BBB
	a2->show();

	AAA* a3 = new CCC;
	a3->fct(); //CCC

	delete a2;
	delete a3;

	return 0;
}