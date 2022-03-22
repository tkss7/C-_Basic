//const_Person.cpp
#include<iostream>
using namespace std;
/*
	mutable int age; // 상수화된 메서드에서 수정 가능

	Student(int _id, const char *_name, const char*_major,int _age):id(_id) //상수화된 멤버는 콜론초기화로 초기화 한다.

	void ShowData() const //이 메서드 안에서는 멤버를 수정하지않는다.
	{
		showStudentIntro(); //상수화된 메서드 안에서는 상수화된 메서드만 부를 수 있다. !!!

		age = 27; //상수화 된 메서드이므로 수정 불가함, 하지만 mutable로 정의하면 수정 가능함

		strcpy(name, "AAA"); //상수화 된 메서드이므로 수정 불가함
	}

	void showStudentIntro() const //이렇게 해야 상수화 한 메서드에서 부를 수 있다.

	const char *getName() const // 상수화된 메서드가 주소를 반환 할 때는 반환값도 상수화 되어야한다.
	{
		return name;
	}

	const char* _name = st1.getName(); // 반환된 상수화된 값을 받기 위해서는 받을때도 const를 사용해야한다.

*/
class Student
{
private:
	const int id;
	mutable int age; // 상수화된 메서드에서 수정 가능
	char name[20];
	char major[20];
public:

	Student(int _id, const char *_name, const char*_major,int _age):id(_id) // 
	{
		//id = _id; //상수화된 멤버는 콜론초기화로 초기화 한다.
		strcpy(name, _name);
		strcpy(major, _major);
	}

	void ShowData() const //이 메서드 안에서는 멤버를 수정하지않는다.
	{
		showStudentIntro(); //상수화된 메서드 안에서는 상수화된 메서드만 부를 수 있다. !!!

		age = 27; //상수화 된 메서드이므로 수정 불가함, 하지만 mutable로 정의하면 수정 가능함
		//strcpy(name, "AAA"); 상수화 된 메서드이므로 수정 불가함
		cout << id << ", "<<name << ", " << major << ", " << age << endl;
	}

	void showStudentIntro() const //이렇게 해야 부를 수 있다.
	{
		cout << "== 학생정보 출력 ==" << endl;
	}

	const char *getName() const // 상수화된 메서드가 주소를 반환 할 때는 반환값도 상수화 되어야한다.
								// 반환된 상수화된 값을 받기 위해서는 받을때도 const를 사용해야한다.
	{
		return name;
	}

};

int main()
{
	Student st1(1001, "kim", "computer", 25);
	st1.ShowData();

	cout << "성명 : " << st1.getName() << endl;

	const char* _name = st1.getName(); // 반환된 상수화된 값을 받기 위해서는 받을때도 const를 사용해야한다.
	cout << "성명 : " << _name << endl;

	return 0;
}