//9_Person_Construct1.cpp 03/18
#include<iostream>
#include<cstring>
#include<vld.h>
using namespace std;


//생성자를 작성하여 다음을 출력하시오.
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
	Person() :Person("", "", 0) {} // 이렇게 이웃생성자를 사용하는게 바람직한 것임
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

	//p1.ShowData(); //가베지 출력

	//Person  p2("KIM", "010-333-5555", 22);
	//p2.ShowData();

	//Person p3 = Person("LEE", "010-111-1234", 37);
	//p3.ShowData();

	Person* p4 = new Person();
	p4->ShowData();

	Person *p5 =new Person("HAN", "010-111-5674", 28); // 동적할당은 포인터만 되는듯?
	p5->ShowData();

	delete p4; //동적할당을 따로 받았으므로 delete를 해줘야 메모리 반환이 완전히 이루어진다.
	delete p5;

	return 0;
}

