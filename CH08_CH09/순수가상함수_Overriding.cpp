//순수가상함수_Overriding.cpp 03/24
#include<iostream>
using namespace std;
/*
	virtual은 상속된다. = 부모클래스쪽에만 줘도 되지만 가독성을 위해 나머지도 다 준다.
	실행시에 바뀌는것
*/
class AAA
{
public:
	virtual void fct() = 0; // 순수 가상함수 : 실행부가 없음
	void show()
	{
		cout << "AAA show()" << endl;
	}

};

class BBB : public AAA
{
public:
	virtual void fct() // 파생 클래스는 반드시 순수 가상함수 구현해야 한다.
	{ // virtual은 상속되므로 자식클래스에는 안써도 된다.
		cout << "class BBB fct()" << endl;
	}
};

class CCC : public BBB
{
public:
	virtual void fct()  // 파생 클래스는 반드시 순수 가상함수 구현해야 한다.
	{
		cout << "class CCC fct()" << endl;
	}
};

int main()
{
	//AAA* a1 = new AAA; //추상 클래스는 객체를 생성할 수 없다.

	AAA* a2 = new BBB();
	a2->fct(); //BBB
	a2->show();

	AAA* a3 = new CCC;
	a3->fct(); //CCC

	delete a2;
	delete a3;

	return 0;
}