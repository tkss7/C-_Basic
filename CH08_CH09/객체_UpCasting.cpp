//��ü_UpCasting.cpp
#include<iostream>
using namespace std;

class Person
{
public:
	void Sleep()
	{
		cout << "Sleep()" << endl;
	}

};

class Student :public Person
{

public:
	void study()
	{
		cout << "Study()" << endl;
	}
};

class partTimeStd : public Student
{
private:
	int  ptNum;
public:
	partTimeStd() : ptNum(100)
	{

	}

	void Work()
	{
		cout << "Work() :" << ptNum << endl;
	}
};

int main()
{
	Person t1;
	Student t2;
	partTimeStd t3;

	t1.Sleep();
	t2.Sleep();
	t2.study();
	t3.Sleep();
	t3.study();
	t3.Work();
	cout << "====================" << endl;

	//�θ�Ŭ���� �����ʹ� �ڽ�Ŭ���� �����͸� ������ �� �ִ�.
	//Person* p1; // �θ�Ŭ������ ��ü�����ʹ� �ڽ� �Ӹ��ƴ϶� �Ļ�Ŭ������ �ּҵ� ���� �� �ִ�.  => ���⼺

	Person* p1 = new Person();
	Person* p2 = new Student(); // UpCast
	Person* p3 = new partTimeStd();

	//���Ŭ������ ��ü �����ʹ� ����Ű�� ��� ������� 
	//���Ŭ���� ���� ����� ����� �����Ѵ�.
	p1->Sleep();
	p2->Sleep();
	//p2->Study(); // Error : ����� �޾����� ��ü�����Ͱ� ���Ŭ���� Ÿ���̹Ƿ� ���� �Ұ�
	p3->Sleep();
	//p3->PartTimeStd::Work(); // Error : ����� �޾����� ��ü�����Ͱ� ���Ŭ���� Ÿ���̹Ƿ� ���� �Ұ�

	Student* s1 = new partTimeStd();
	s1->Sleep();
	s1->study();
	cout << "====================" << endl;

	//�Ļ�Ŭ���� ��ü�����ʹ� ���Ŭ���� �ּҸ� ������ �� ����.
	//partTimeStd *pt1 = new Person; //Down Cast
	//partTimeStd* pt1 = p1;

	//partTimeStd* pt1 = (partTimeStd*)p1; // ����� ����ȯ, C Style ==> �ٿ� ĳ��Ʈ�� �⺻������ �Ⱦ���.
	partTimeStd* pt1 = (static_cast<partTimeStd*>(p1)); // ����� ����ȯ, C++ Style ==> �ٿ� ĳ��Ʈ�� �⺻������ �Ⱦ���.
	pt1->Sleep();
	pt1->study();
	pt1->Work();

	cout << "======================" << endl;


	return 0;
}
/*
	AAA Ŭ������ �����ʹ� AAA��ü�Ӹ��ƴ϶� �ڽ�Ŭ���� ��ü�� �ּҰ��� ���� ����
	AAA Ŭ������ �����ʹ� AAAŬ���� ���� ����� ������� ���ٰ���
	�ڽ� Ŭ������ �����ʹ� �θ�Ŭ���� ��ü�� �ּҸ� ������ �� ����. (�ٿ�ĳ��Ʈ)
	���Ŭ������ ��ü �����ʹ� ����Ű�� ��� �������
	//���Ŭ���� ���� ����� ����� �����Ѵ�.

	�ڽ� Ŭ���� ��ü�� �θ� Ŭ���� ��ü�� �޼ҵ带 ���� ����� �� �� ������

	�θ�Ŭ���� ��ü �����ʹ� �ڽ� Ŭ���� ��ü�� �ּҸ� ���� �� ������, ���� �ڽ� ��ü ���� ������ ��Ÿ������ ���Ѵ�.

*/