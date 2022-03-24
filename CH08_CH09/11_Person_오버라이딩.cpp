#include <iostream>
using namespace std;

/*
다음과 같이 실행시키는 코드를 완성하시오.

실행결과
이름: 이몽룡, 나이: 16
이름: Hong Gil Dong, 나이: 20, 전공: computer
*/

class Person
{
protected:
	int age;
	char name[20];
public:
	Person(int _age = 1, const char* _name = "noName")
	{
		age = _age;
		strcpy(name, _name);
	}

	void ShowData()
	{
		cout << "이름 : " << name << ", 나이 : " << age ;
	}
};

class Student : public Person
{
	char major[20]; //전공
public:
	Student(int _age, const char* _name, const char* _major):Person(_age, _name)
	{
		strcpy(major, _major);
	}

	void ShowData()
	{
		cout << endl;
		Person::ShowData();
		//cout << "이름 : " << name;
		//cout << ", 나이 : " << age;
		cout<< ", 전공 : " << major << endl;
	}
	
};

int main()
{
	Person Lee(16, "이몽룡");
	Lee.ShowData();

	Student Kim(20, "Hong Gil Dong", "computer");
	Kim.ShowData();

	return 0;
};