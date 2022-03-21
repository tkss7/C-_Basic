//this_pointer.cpp 03/18
#include<iostream>
using namespace std;
class Person
{ // this는 객체 자신에 대한 포인터임
private:
	int age = 0;
public:
	void showData()
	{
		cout << "age : " << age << endl;
	}

	Person *getThis() //얘를 부른 객체의 주소값을 가짐
	{
		return this; //자기멤버를 가리킴 // 이 메소드를 부른 객체의 주소를 가리킴
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
	cout << "포인터 p1 : " << p1 << endl;
	cout << "p1 this 포인터 : " << p1->getThis() << endl;

	Person* p2 = new Person();
	cout << "포인터 p2 : " << p2 << endl;
	cout << "p2 this 포인터 : " << p2->getThis() << endl << endl;

	cout << "객체반환" << endl;
	Person p3 = p2->getThis2();
	p2->showData();
	p3.showData();
	
	delete p1;
	delete p2;

	Person per1;
	cout << "&per1 : " << &per1 << endl;
	cout << "per1.getThis 포인터 : " << per1.getThis() << endl;
	return 0;
}