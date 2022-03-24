#include <iostream>
using namespace std;

/*
������ ���� �����Ű�� �ڵ带 �ϼ��Ͻÿ�.

������
�̸�: �̸���, ����: 16
�̸�: Hong Gil Dong, ����: 20, ����: computer
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
		cout << "�̸� : " << name << ", ���� : " << age ;
	}
};

class Student : public Person
{
	char major[20]; //����
public:
	Student(int _age, const char* _name, const char* _major):Person(_age, _name)
	{
		strcpy(major, _major);
	}

	void ShowData()
	{
		cout << endl;
		Person::ShowData();
		//cout << "�̸� : " << name;
		//cout << ", ���� : " << age;
		cout<< ", ���� : " << major << endl;
	}
	
};

int main()
{
	Person Lee(16, "�̸���");
	Lee.ShowData();

	Student Kim(20, "Hong Gil Dong", "computer");
	Kim.ShowData();

	return 0;
};