#include <iostream>
#include <cstring>
#include<vld.h>
using namespace std;

/*
다음과 같이 실행되는 코드를 완성하시오.

실행결과
My name is kim
My age is 10

My name is Lee
My age is 22
My major is Computer eng.

~Student() called. 
~Person() called.
~Person() called.

*/

class Person
{
private:
	char* name;     // 이름
	int age;        // 나이

public:

	Person(const char* _name, int _age)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		age = _age;

	}

	~Person()
	{
		cout << "~Person() called" << endl;
		delete[] name;
	}

	void ShowPerson() const
	{
		cout << "My name is " << name << endl;
		cout << "My age is " << age << endl;
	}
};

class Student : public Person
{
private:
	char* major;     // 전공과목

public:

	Student(const char* _name, int _age, const char* _major) :Person(_name, _age)// 명시적 호출
	{
		major = new char[strlen(_major) + 1];
		strcpy(major, _major);
	}

	~Student()
	{
		delete[] major;
		cout << "~Student() called" << endl;
	}

	void ShowStudent() const
	{
		ShowPerson();
		cout << "My major is " << major << endl << endl;
	}
};

int main()
{
	Person emp("Kim", 10);
	emp.ShowPerson();
	cout << endl;

	Student st1("Lee", 22, "Computer eng.");
	st1.ShowStudent();

	return 0;
};