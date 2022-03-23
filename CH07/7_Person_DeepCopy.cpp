//7_Person_DeepCopy.cpp
#include<iostream>
#include<cstring>
#include<vld.h>
using namespace std;


class Person
{
private:
	char *name;
	char *phone;
	int age = 0;
public:
	void ShowData();

	//3. ����Ʈ������ �߰�
	Person() 
	{
		name = NULL;
		phone = NULL;
	}
	
	//2. ������ �ۼ�
	Person(const char* _name, const char* _phone, int _age);

	Person(const Person& p);

	~Person()
	{
		cout << "~Person() " << endl;
		delete name;
		delete phone;
	}
	Person& operator=(const Person& ref);

	
};

Person::Person(const char* _name, const char* _phone, int _age)
{
	cout << "Person(const char* _name, const char* _phone, int _age)" << endl;

	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	phone = new char[strlen(_phone) + 1];
	strcpy(phone, _phone);
	age = _age;
}

void Person::ShowData()
{
	cout << "name: " << name << ", phone: " << phone << ", age: " << age << endl;
}

Person::Person(const Person& p)
{
	cout << "Person(Person &p)" << endl;
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name, p.name);
	this->phone = new char[strlen(p.phone) + 1];
	strcpy(this->phone, p.phone);
	this->age = p.age;
}

Person& Person::operator=(const Person& ref)
{
	cout << "Person(Person &ref)" << endl;

	if (this->name != NULL) //���� �ּҸ� ������ �� �����Ƿ� �� ���� �����Ѵ�.
	{
		delete[] this->name;
		delete[] this->phone;
	}

	this->name = new char[strlen(ref.name) + 1];
	strcpy(this->name, ref.name);
	this->phone = new char[strlen(ref.phone) + 1];
	strcpy(this->phone, ref.phone);
	this->age = ref.age;
	return *this;
}

int main()
{
//1.�����ڸ� �̿��� ����ʱ�ȭ
	Person  p1("KIM", "010-333-5555", 22); 
	p1.ShowData();

	Person p2 = p1;
	p2.ShowData();

	Person p3;
	p3 = p1;	//����Ʈ ���Կ����ڰ� ȣ��(�ȸ���� �ڵ�����) : ����� �ϳ��� �����Ҵ��� �ް� ������ ����� ���� ���Կ����ڸ� ����� ��� �Ѵ�.!!!
	p3.ShowData();
	cout << "=============================" << endl;

	Person p4("Lee", "010-333-1234", 27);
	p1 = p4;
	p1.ShowData();


	return 0;
}
/*
Person(const char* _name, const char* _phone, int _age)
name: KIM, phone: 010-333-5555, age: 22
name: KIM, phone: 010-333-5555, age: 22
~Person()
~Person()
*/