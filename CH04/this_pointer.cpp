//this_pointer.cpp 03/18
#include<iostream>
using namespace std;
class Person
{ // this�� ��ü �ڽſ� ���� ��������
private:
	int age = 0;
public:
	void showData()
	{
		cout << "age : " << age << endl;
	}

	Person *getThis() //�긦 �θ� ��ü�� �ּҰ��� ����
	{
		return this; //�ڱ����� ����Ŵ // �� �޼ҵ带 �θ� ��ü�� �ּҸ� ����Ŵ
	}
	Person getThis2()
	{
		this->age = 25;
		return *this;
	}
};
int main()
{
	Person* p1 = new Person();
	cout << "������ p1 : " << p1 << endl;
	cout << "p1 this ������ : " << p1->getThis() << endl;

	Person* p2 = new Person();
	cout << "������ p2 : " << p2 << endl;
	cout << "p2 this ������ : " << p2->getThis() << endl << endl;

	cout << "��ü��ȯ" << endl;
	Person p3 = p2->getThis2();
	p2->showData();
	p3.showData();
	
	delete p1;
	delete p2;

	Person per1;
	cout << "&per1 : " << &per1 << endl;
	cout << "per1.getThis ������ : " << per1.getThis() << endl;
	return 0;
}