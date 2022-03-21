#include<iostream>
using namespace std;


class Person
{
private:
	char *name;
	char *phone;
	int age = 0;
public:
	void ShowData();

	//3. 디폴트생성자 추가
	Person()
	{

	}

	//2. 생성자 작성
	Person(const char* _name, const char* _phone, int _age)
	{
		cout <<"Person(const char* _name, const char* _phone, int _age)"<< endl;

		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		phone = new char[strlen(_phone) + 1];
		strcpy(phone, _phone);
		age = _age;
	}
	Person(const Person &p)
	{
		cout << "Person(Person &p)" << endl;
		this->name = new char[strlen(p.name) + 1];
		strcpy(this->name, p.name);
		this->phone = new char[strlen(p.phone) + 1];
		strcpy(this->phone, p.phone);
		this->age = p.age;
	}

	~Person()
	{
		cout << "~Person() " << endl;
		delete name;
		delete phone;
	}
};

void Person::ShowData()
{
	cout << "name: " << name << ", phone: " << phone << ", age: " << age << endl;
}

int main()
{
//1.생성자를 이용한 멤버초기화
	Person  p1("KIM", "010-333-5555", 22); 
	p1.ShowData();

	Person p2 = p1;
	p2.ShowData();

	return 0;
}
/*
Person(const char* _name, const char* _phone, int _age)
name: KIM, phone: 010-333-5555, age: 22
name: KIM, phone: 010-333-5555, age: 22
~Person()
~Person()
*/