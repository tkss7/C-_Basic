#include <iostream>
using namespace std;
/*
A 클래스의 레퍼런스를 참조하는 대상이 어떠한 객체이건, 
A클래스 타입내에 선언된 멤버과 상속된 클래스에만 접근이 가능한다.
파생클래스의 객체에는 기본클래스에서 선언된 멤버들과 파생 클래스에서 선언한 멤버들이 모두 존재하기 때문에 ,
파생클래스 객체를 파생클래스의 포인터나 기본클래스의 포인터로 모두 가리킬 수 있다.

업캐스팅 : 기본클래스의  포인터로 파생클래스의 객체를  가리키는 것을 말함
			파생클래스의 객체를 기본클래스의 객체처럼 다룰 수 있게 한다.
			기본클래스의 포인터는 자식클래스의 객체 내의 기본클래스 객체의 멤버만 접근 가능하다.
			업캐스팅은 명시적 타입변환 필요 x 
			부모클래스 포인터 = 자식클래스 객체  : 우 -> 좌 연산이므로 작은것에서 큰것 = UP CAST

다운 캐스팅 : 자식클래스의 포인터로 기본클래스 포인터가 가리키는 객체를 가리키는것
			자식클래스 포인터 = (자식클래스 *)부모클래스 포인터 : 우-> 좌 연산이므로  큰것에서 작은것 =DOWN CAST
			명시적 타입변환이 필수 !!!
			업캐스팅 한 부모클래스 포인터를  대입 재료로 써야 다운캐스팅?


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