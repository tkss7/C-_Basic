//Circle.cpp 03/17
#include<iostream>
using namespace std;
// 일반적인 형태는 클래스안에 선언만 하고 클래스 밖에 ::을 사용해서 만듦
class Circle {
public:
	int radius;

	int GetRadius()
	{
		return radius;
	}
	double GetArea();  // 반드시 선언해야 메소드 인식
};
double Circle::GetArea() // 이렇게 하면 클래스 밖에 있어도  서클 클래스 안에 있는 메소드라고 인식함
{
	return radius * radius * 3.15;
}
int main()
{
	Circle donut;

	donut.radius = 1;
	cout << "반지름 : " << donut.GetRadius() << endl;

	double area = donut.GetArea();
	cout << "면적 : " << donut.GetArea() << endl;

	Circle pizza;
	pizza.radius = 5;
	cout << "면적 : " << pizza.GetArea() << endl;
	return 0;
}