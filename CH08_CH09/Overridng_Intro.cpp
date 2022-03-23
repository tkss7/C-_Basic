//Overridng_Intro.cpp
#include<iostream>
using namespace std;
/*
	메서드 오버라이딩(Overriding) : 함수 재정의(다형성)
	메서드 오버로딩(Overloading) : 함수 중복정의
*/
class AAA
{
public:
	void fct()
	{
		cout << "class AAA fct()" << endl;
	}
};

class BBB : public AAA
{
public:
	void fct() //메서드 오버라이딩
	{
		cout << "class BBB fct()" << endl;
	}
};

int main()
{
	BBB b1; //오버라이딩한 자신의 메서드를 호출한다. 기반클래스 메서드는 가리는 효과
	b1.fct();
	b1.AAA::fct(); //명시적 호출

	BBB* b2 = new BBB;
	b2->fct();
	b2->AAA::fct(); //명시적 호출

	AAA* a1 = b2; //Up Cast
	a1->fct(); //AAA 메서드 호출		//객체포인터는 기본적으로 자신의 멤버,메서드만 부른다.
	
	//a1->BBB::fct(); // Error : 기반클래스 포인터는 파생클래스 객체를 가리킬 수 없다.

	return 0;
}