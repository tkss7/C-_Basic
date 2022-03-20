//9_Person_Construct1.cpp 03/18
#include<iostream>
#include<cstring>
#include<vld.h>
using namespace std;


//�����ڸ� �ۼ��Ͽ� ������ ����Ͻÿ�.
/*
name: , phone: , age: 0
name: KIM, phone: 010-333-5555, age: 22
name: LEE, phone: 010-111-1234, age: 37
*/

const int SIZE = 20;

class Person
{
private:
	char name[SIZE];
	char phone[SIZE];
	int age;
public:
	//Person() 
	//{
	//	strcpy(name, "");
	//	strcpy(phone, "");
	//	age = 0;
	//}
	Person() :Person("", "", 0) {} // �̷��� �̿������ڸ� ����ϴ°� �ٶ����� ����
	Person(const char *name2, const char *phone2, int age2)
	{
		strcpy(name, name2);
		strcpy(phone, phone2);
		age = age2;
	}
	~Person()
	{
		cout << "~Person() : age : " <<age<< endl;
	}
	void ShowData();

};

void Person::ShowData()
{
	cout << "name: " << name << ", phone: " << phone << ", age: " << age << endl;
}

int main()
{
	//Person p1;

	//p1.ShowData(); //������ ���

	//Person  p2("KIM", "010-333-5555", 22);
	//p2.ShowData();

	//Person p3 = Person("LEE", "010-111-1234", 37);
	//p3.ShowData();

	Person* p4 = new Person();
	p4->ShowData();

	Person *p5 =new Person("HAN", "010-111-5674", 28); // �����Ҵ��� �����͸� �Ǵµ�?
	p5->ShowData();

	delete p4; //�����Ҵ��� ���� �޾����Ƿ� delete�� ����� �޸� ��ȯ�� ������ �̷������.
	delete p5;

	return 0;
}

