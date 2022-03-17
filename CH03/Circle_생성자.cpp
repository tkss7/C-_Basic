//Circle_생성자.cpp 03/17
#include<iostream>
//생성자가 먼저 불러지고 그에 따라 메모리가 할당된다.
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
	cout << "반지름 : " << donut.getRadius() << endl;

	Circle pizza(30);
	cout << "반지름 : " << pizza.getRadius() << endl;
	cout << "===================" << endl;

	Circle c1; //빈괄호 생성자 Circle()
	Circle c2(1); // 정수값을 갖고있는 생성자 Circle(int r)
	Circle c3 =  Circle(); //생성자 명시적 호출, Circle()
	Circle c4 =  Circle(3); // 정수값을 갖고있는 생성자 명시적 호출, Circle(int r)

	Circle c5(); // 함수 선언문 // c5라는 인수를 안 받는 return값 Circle의 함수 생성




	return 0;
}