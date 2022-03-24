//Overriding_Virtual_Intro.cpp 03/24
#include<iostream>
using namespace std;
/*
	virtual은 상속된다. = 부모클래스쪽에만 줘도 되지만 가독성을 위해 나머지도 다 준다.
	실행시에 바뀌는것
*/
class AAA
{
public:
	virtual void fct()
	{
		cout << "class AAA fct()" << endl;
	}
};

class BBB : public AAA // 상속받는 자식클래스의 가상함수는
{
public:
	virtual void fct() //메서드 오버라이딩
	{
		cout << "class BBB fct()" << endl;
	}
};

class CCC : public BBB
{
public:
	virtual void fct() //메서드 오버라이딩
	{
		cout << "class CCC fct()" << endl;
	}
};

int main()
{
	BBB* b1 = new BBB;
	b1->fct(); // BBB
	b1->AAA::fct(); // AAA
	cout << "==========================================" << endl;

	//기반클래스 포인터가 파생클래스 메서드를 호출한다.
	//실행시 기반클래스를 가린다(즉 실행시 파생클래스 주소변경, 동적결합)
	// 함수가 virtual이 되면 객체포인터 타입과 관계없이, 가르키는 대상 객체가 기준이 된다.
	AAA* a1 = new BBB;
	a1->fct(); // AAA , virtual => BBB

	AAA* a2 = new CCC;
	a2->fct(); // CCC

	BBB* b2 = new CCC;
	b2->fct(); // CCC
cout << "============================================" << endl;

	AAA* a3 = b2;
	a3->fct(); // CCC
	a3->AAA::fct(); // AAA
	//a3->CCC::fct();
	//a3->BBB::fct();
	
	AAA* a4 = new AAA;
	//CCC* c1 = a4; // Down Cast
	return 0;
}