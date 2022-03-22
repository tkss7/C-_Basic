//const_Person.cpp
#include<iostream>
using namespace std;
/*
	mutable int age; // ���ȭ�� �޼��忡�� ���� ����

	Student(int _id, const char *_name, const char*_major,int _age):id(_id) //���ȭ�� ����� �ݷ��ʱ�ȭ�� �ʱ�ȭ �Ѵ�.

	void ShowData() const //�� �޼��� �ȿ����� ����� ���������ʴ´�.
	{
		showStudentIntro(); //���ȭ�� �޼��� �ȿ����� ���ȭ�� �޼��常 �θ� �� �ִ�. !!!

		age = 27; //���ȭ �� �޼����̹Ƿ� ���� �Ұ���, ������ mutable�� �����ϸ� ���� ������

		strcpy(name, "AAA"); //���ȭ �� �޼����̹Ƿ� ���� �Ұ���
	}

	void showStudentIntro() const //�̷��� �ؾ� ���ȭ �� �޼��忡�� �θ� �� �ִ�.

	const char *getName() const // ���ȭ�� �޼��尡 �ּҸ� ��ȯ �� ���� ��ȯ���� ���ȭ �Ǿ���Ѵ�.
	{
		return name;
	}

	const char* _name = st1.getName(); // ��ȯ�� ���ȭ�� ���� �ޱ� ���ؼ��� �������� const�� ����ؾ��Ѵ�.

*/
class Student
{
private:
	const int id;
	mutable int age; // ���ȭ�� �޼��忡�� ���� ����
	char name[20];
	char major[20];
public:

	Student(int _id, const char *_name, const char*_major,int _age):id(_id) // 
	{
		//id = _id; //���ȭ�� ����� �ݷ��ʱ�ȭ�� �ʱ�ȭ �Ѵ�.
		strcpy(name, _name);
		strcpy(major, _major);
	}

	void ShowData() const //�� �޼��� �ȿ����� ����� ���������ʴ´�.
	{
		showStudentIntro(); //���ȭ�� �޼��� �ȿ����� ���ȭ�� �޼��常 �θ� �� �ִ�. !!!

		age = 27; //���ȭ �� �޼����̹Ƿ� ���� �Ұ���, ������ mutable�� �����ϸ� ���� ������
		//strcpy(name, "AAA"); ���ȭ �� �޼����̹Ƿ� ���� �Ұ���
		cout << id << ", "<<name << ", " << major << ", " << age << endl;
	}

	void showStudentIntro() const //�̷��� �ؾ� �θ� �� �ִ�.
	{
		cout << "== �л����� ��� ==" << endl;
	}

	const char *getName() const // ���ȭ�� �޼��尡 �ּҸ� ��ȯ �� ���� ��ȯ���� ���ȭ �Ǿ���Ѵ�.
								// ��ȯ�� ���ȭ�� ���� �ޱ� ���ؼ��� �������� const�� ����ؾ��Ѵ�.
	{
		return name;
	}

};

int main()
{
	Student st1(1001, "kim", "computer", 25);
	st1.ShowData();

	cout << "���� : " << st1.getName() << endl;

	const char* _name = st1.getName(); // ��ȯ�� ���ȭ�� ���� �ޱ� ���ؼ��� �������� const�� ����ؾ��Ѵ�.
	cout << "���� : " << _name << endl;

	return 0;
}