//Circle_소멸자.cpp 03/18
#include<iostream>
#include<vld.h>
using namespace std;
class Circle {
private:
	int radius;
public:
	Circle() // 생성자 : 주로 멤버 초기화를 하는게 목적임
	{
		cout << "Circle()" << endl;
		radius = 0;
	}
	~Circle() //소멸자, 개체소멸 전 실행
	{
		cout << "~Circle() : " << radius << endl;
	}
	Circle(int r) // 정수를 인자로 받는 생성자
	{
		cout << "Circle(int r)" << endl;
		radius = r;
	}
	int getRadius()
	{
		return radius;
	}
	double getArea();

};
double Circle::getArea() // 이렇게 하면 클래스 밖에 있어도  서클 클래스 안에 있는 메소드라고 인식함
{
	return radius * radius * 3.15;
}
int main()
{
	Circle donut; //객체는 생성과 동시에 생성자 호출
	Circle pizza(30);

	return 0;
}