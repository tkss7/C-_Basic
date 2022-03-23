#include <iostream>
using namespace std;

class Base
{
private:
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	Base():a(1)
	{}
	void showA() { cout << a<<" , "; }
};

//private 상속은 접근 기반 클래스 멤버의 접근지정자와 관계없이  private으로 접근
class Derived1 : private Base  
{
private:
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	Derived1(): b(2)
	{}
	void showB() { cout << b << " , "; }
};

//protected 상속은 접근 기반 클래스 멤버의 접근지정자와 관계없이  protected로 접근
class Derived2 : protected Base  
{
private:
	int c;
protected:
	void setC(int c) { this->c = c; }
public:
	Derived2(): c(3)
	{}
	void showC() 
	{ 
		showA();   //1
		cout << c << " , "; //3
	}
};

class Derived3 : public Base
{
private:
	int d;
protected:
	void setD(int d) { this->d = d; }
public:
	Derived3():d(4)
	{}
	void showD() { cout << d << " , "; }
};

int main()
{
	Base b1;
	b1.showA();  //1
	cout << endl;

	Derived1 d1;  //private Base 상속
	d1.showB();   //2, // 자신의 메서드만 호출, 그외 나머지 접근 불가
	cout << endl;

	Derived2 d2;  //protected Base 상속
	d2.showC();   //1,3  // 자신의 메서드만 호출, 그외 나머지 접근 불가
	              // 그러나  Derived2 showC() 메서드에서는 showA() 호출가능
	cout << endl;

	Derived3 d3;  //public Base 상속
	d3.showA();   //1
	cout << endl;
	d3.showD();   //4
}

