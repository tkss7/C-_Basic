//STL_Map_Student.cpp 03/30
#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
학번, 이름, 지역명 ?  1001 kim seoul
전공, 학점 ? it 3.1
학번, 이름, 지역명 ?  2001 lee busan
학위 입력 : 교육학석사
학번, 이름, 지역명 ?  1002 han inchoen
전공, 학점 ? 간호학 4.2
학번, 이름, 지역명 ?  2002 park suwon
학위 입력 : 이학학사

학번 : 1001, 이름 : kim, 지역 : seoul , 전공 : it, 학점 : 3.1
학번 : 1002, 이름 : han, 지역 : inchoen , 전공 : 간호학, 학점 : 4.2
학번 : 2001, 이름 : lee, 지역 : busan , 학위 : 교육학석사
학번 : 2002, 이름 : park, 지역 : suwon , 학위 : 이학학사
==========================
검색할 ID ? (종료:end) 1002
학번 : 1002, 이름 : han, 지역 : inchoen , 전공 : 간호학, 학점 : 4.2
검색할 ID ? (종료:end) 1005
검색한 ID가  없습니다.
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
	cout << "학번 : " << id << ", 이름 : " << name << ", 지역 : " << city;

}

void Student::input()
{
	cout << "학번, 이름, 지역명 ?  ";
	cin >> id >> name >> city;
}

class University : public Student   //대학정보를 저장하는 클래스
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
	cout << " , 전공 : " << major << ", 학점 : " << grade << endl;
}

void University::input()
{
	Student::input();
	cout << "전공, 학점 ? ";
	cin >> major >> grade;
}

class PostGraduate : public Student   //대학원 정보를 저장하는 클래스
{
private:
	string degree;  //학위
public:
	virtual void print();
	virtual void input();
};

void PostGraduate::print()  
{
	Student::print();
	cout << " , 학위 : " << degree << endl;

}

void PostGraduate::input()
{
	Student::input();
	cout << "학위 입력 : ";
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
		cout << "\n검색할 ID ? (종료:end) ";
		cin >> inputID;
		if (inputID == "end")
			break;
		itr = mapStudent.find(inputID);  //키를 찾는다
		if (itr == mapStudent.end())
			cout << "검색한 ID가  없습니다." << endl;
		else
			itr->second->print();
	}
}

