#include <iostream>
using namespace std;
/*
A 클래스의 레퍼런스를 참조하는 대상이 어떠한 객체이건, 
A클래스 타입내에 선언된 멤버과 상속된 클래스에만 접근이 가능한다.
*/

//1.클래스 생성
class Person
{
public:
	void Sleep(){ 
		cout<<"Sleep"<<endl;
	}
};

class Student : public Person
{
public:
	void Study(){
		cout<<"Study"<<endl;
	}
};

class PartTimeStd : public Student
{
public:
	void Work(){
		cout<<"Work"<<endl;
	}
};

int main()
{
//2. 
	//객체를 참조하는 레퍼런스의 권한
    //클래스 포인터의 권한과 일치!
	PartTimeStd pt;
	Student &Sref1=pt;
	Person &Pref2=pt;
	
	pt.Sleep();  //세 메서드 모두 호출가능
	Sref1.Sleep();  //sleep,  study 만 가능
	Pref2.Sleep();  //sleep  만 가능
	
	//Pref2.Study(); // Error의 원인, 클래스포인터 권한과 일치
	//Pref2.Work();  // Error의 
	//Pref2.PartTimeStd::Work(); // Error

	return 0;
}