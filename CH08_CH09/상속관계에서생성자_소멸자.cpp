//상속관계에서생성자_소멸자.cpp
#include<iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	//SoBase() 
	//{
	//	cout << "SoBase() " << endl;
	//}

	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n) : "<< baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}

};

class SoDerived : public SoBase 
{
private:
	int devNum;
public:
	SoDerived(int n) : SoBase(n) //기본클래스의 명시적 호출
	{
		devNum = n;
		cout << "SoDerived(int n) : " << devNum << endl;
	}

	~SoDerived()
	{
		cout << "~SoDerived() : " << devNum << endl;
	}
};

int main()
{
	SoDerived dr1(100); //자식객체를 생성하면 부모클래스의 빈괄호 생성자 -> 자식클래스의 생성자를 부른다.
	//파생클래스의 객체를 호출하면 반드시 기본클래스의 빈괄호 생성자가 필요하다.

	return 0;
}