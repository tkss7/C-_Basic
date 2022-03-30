//STL_Map_Student.cpp 03/30
#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
�й�, �̸�, ������ ?  1001 kim seoul
����, ���� ? it 3.1
�й�, �̸�, ������ ?  2001 lee busan
���� �Է� : �����м���
�й�, �̸�, ������ ?  1002 han inchoen
����, ���� ? ��ȣ�� 4.2
�й�, �̸�, ������ ?  2002 park suwon
���� �Է� : �����л�

�й� : 1001, �̸� : kim, ���� : seoul , ���� : it, ���� : 3.1
�й� : 1002, �̸� : han, ���� : inchoen , ���� : ��ȣ��, ���� : 4.2
�й� : 2001, �̸� : lee, ���� : busan , ���� : �����м���
�й� : 2002, �̸� : park, ���� : suwon , ���� : �����л�
==========================
�˻��� ID ? (����:end) 1002
�й� : 1002, �̸� : han, ���� : inchoen , ���� : ��ȣ��, ���� : 4.2
�˻��� ID ? (����:end) 1005
�˻��� ID��  �����ϴ�.
*/

class Student
{
private:
	string name;
	string id;
	string city;
public:
	string GetID() const { return id; }
	virtual void print();
	virtual void input();
};

void Student::print()
{
	cout << "�й� : " << id << ", �̸� : " << name << ", ���� : " << city;

}

void Student::input()
{
	cout << "�й�, �̸�, ������ ?  ";
	cin >> id >> name >> city;
}

class University : public Student   //���������� �����ϴ� Ŭ����
{
private:                          
	string major;
	float grade;

public:
	virtual void print();
	virtual void input();

};

void University::print()
{
	Student::print();
	cout << " , ���� : " << major << ", ���� : " << grade << endl;
}

void University::input()
{
	Student::input();
	cout << "����, ���� ? ";
	cin >> major >> grade;
}

class PostGraduate : public Student   //���п� ������ �����ϴ� Ŭ����
{
private:
	string degree;  //����
public:
	virtual void print();
	virtual void input();
};

void PostGraduate::print()  
{
	Student::print();
	cout << " , ���� : " << degree << endl;

}

void PostGraduate::input()
{
	Student::input();
	cout << "���� �Է� : ";
	cin >> degree;
}

#define  ArrSize 2

int main()
{
	map<string, Student*> mapStudent;

	University univ[ArrSize];
	PostGraduate post[ArrSize];
	string inputID;

	for (int i = 0; i < ArrSize; i++)
	{
		univ[i].input();
		post[i].input();
	}

	for (int i = 0; i < ArrSize; i++)
	{
		mapStudent.insert(make_pair(univ[i].GetID(), (Student*)&univ[i]));
		mapStudent.insert(make_pair(post[i].GetID(), (Student*)&post[i]));
	}

	map<string, Student*> ::iterator itr = mapStudent.begin();

	cout << endl;
	while (itr != mapStudent.end())
	{
		itr->second->print();
		itr++;
	}
	cout << "==========================" << endl;

	while (1)
	{
		cout << endl;
		cout << "\n�˻��� ID ? (����:end) ";
		cin >> inputID;
		if (inputID == "end")
			break;
		itr = mapStudent.find(inputID);  //Ű�� ã�´�
		if (itr == mapStudent.end())
			cout << "�˻��� ID��  �����ϴ�." << endl;
		else
			itr->second->print();
	}
}

