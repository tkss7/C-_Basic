#include<iostream>
using namespace std;


//생성자를 작성하여 다음을 출력하시오.
/*
name: , phone: , age: 0
name: KIM, phone: 010-333-5555, age: 22
name: LEE, phone: 010-111-1234, age: 37
*/

const int SIZE = 20;

//class Person
//{
//private:
//	char name[SIZE] = "";
//	char phone[SIZE] = "";
//	int age = 0;
//public:
//	void ShowData();
//
//};
//
//void Person::ShowData()
//{
//	cout << "name: " << name << ", phone: " << phone << ", age: " << age << endl;
//}
//
//int main()
//{
//	Person p1;
//
//	p1.ShowData(); //가베지 출력
//
//	Person  p3("KIM", "010-333-5555", 22);
//	p3.ShowData();
//
//	Person p4 = Person("LEE", "010-111-1234", 37);
//	p4.ShowData();
//
//	return 0;
//}
class Person
{
private:
	char name[SIZE] = "";
	char phone[SIZE] = "";
	int age = 0;
public:
	void ShowData();

};

void Person::ShowData()
{
	cout << "name: " << name << ", phone: " << phone << ", age: " << age << endl;
}

int main()
{
	Person p1;

	p1.ShowData(); //가베지 출력

	Person  p3("KIM", "010-333-5555", 22);
	p3.ShowData();

	Person p4 = Person("LEE", "010-111-1234", 37);
	p4.ShowData();

	return 0;
}