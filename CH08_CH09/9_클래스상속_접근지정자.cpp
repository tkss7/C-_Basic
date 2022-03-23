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

//private ����� ���� ��� Ŭ���� ����� ���������ڿ� �������  private���� ����
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

//protected ����� ���� ��� Ŭ���� ����� ���������ڿ� �������  protected�� ����
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

	Derived1 d1;  //private Base ���
	d1.showB();   //2, // �ڽ��� �޼��常 ȣ��, �׿� ������ ���� �Ұ�
	cout << endl;

	Derived2 d2;  //protected Base ���
	d2.showC();   //1,3  // �ڽ��� �޼��常 ȣ��, �׿� ������ ���� �Ұ�
	              // �׷���  Derived2 showC() �޼��忡���� showA() ȣ�Ⱑ��
	cout << endl;

	Derived3 d3;  //public Base ���
	d3.showA();   //1
	cout << endl;
	d3.showD();   //4
}

