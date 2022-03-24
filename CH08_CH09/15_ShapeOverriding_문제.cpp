//15_ShapeOverriding_문제.cpp 03/24

/*
일반적인 도형을 의미하는 Point(좌표값 저장)클래스와 사각형을 의미하는 
Rectangle(좌표,가로,세로) 클래스, 원을 의미하는 Circle(좌표,반지름)클래스를 정의한다.
사각형과 원은 도형의 일종이므로 Point클래스와 상속관계를 구성한다.
다음 main() 함수를 참고하여 다음의 결과를 출력한다.

실행결과
[Rectangle] Position = ( 200, 100) Size = ( 50, 50)
[Circle] Position = ( 300, 100) Radius = 30

===================
[Rectangle] Position = ( 200, 100) Size = ( 50, 50)
[Circle] Position = ( 200, 150) Radius = 50
[Rectangle] Position = ( 50, 10) Size = ( 40, 20)
*/

#include <iostream>
using namespace std;
#include<vld.h>
// 일반적인 '도형'을 상징하는 클래스
class Point //추상 클래스
{
protected:
	double xpos, ypos;
public:
	Point()
	{
		xpos = ypos = 0.0;
	}
	Point(double _x, double _y) 
	{
		xpos = _x;
		ypos = _y;
	}
	//virtual void Draw() const {}; //가상함수
	virtual void Draw() const = 0; //순수 가상함수 : 기능구현을 하지 않는 실수는 범하지 않는 역할?을 해준다.
};


// 사각형을 상징하는 클래스
class Rectangle : public Point
{
private:
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double _x, double _y, double _width, double _height);

	void Draw() const;
};

Rectangle::Rectangle():Point()
{
	width = height = 100.0f;
}

//생성자 구현
Rectangle::Rectangle(double _x, double _y, double _width, double _height):Point(_x, _y)
{
	width = _width;
	height = _height;
}

//메서드 추가
void Rectangle::Draw() const
{
	cout << "[Rectangle] Position = (" << xpos <<"," << ypos << ") Size = (" << width <<"," << height << ")" << endl;
}

// 원을 상징하는 클래스
class Circle : public Point
{
private:
	double radius;
public:
	Circle();
	Circle(double _x, double _y, double _radius);

	void Draw() const;
};

Circle::Circle():Point()
{
	radius = 100.0f;
}

//생성자 구현
Circle::Circle(double _x, double _y, double _radius):Point(_x, _y)
{
	radius = _radius;
}

//메서드 추가
void Circle::Draw() const
{
	cout << "[Circle] Position = (" << xpos <<"," << ypos << ") Radius = " << radius << endl;
	
}

int main()
{
	/*
	// 사각형 객체 생성 및 그리기
	Rectangle r(200, 100, 50, 50);
	r.Draw();

	// 원 객체 생성 및 그리기
	Circle c(300, 100, 30);
	c.Draw();
	cout << endl; // 여기까지는 virtual이 필요 없었음

	cout << "===================" << endl;
	Point* p1 = new Rectangle(200, 100, 50, 50);
	p1->Draw();
	Point* p2 = new Circle(200, 150, 50);
	p2->Draw();
	Point* p3 = new Rectangle(50, 10, 40, 20);
	p3->Draw();
*/
	Point* Shape[10] = { NULL };
	//Point* Sape = new Point; // 추상클래스이므로 기반클래스 객체 생성 못함
	//Point* Sape = new Rectangle(200, 100, 50, 50);

	Shape[0] = new Rectangle(200, 100, 50, 50);
	Shape[1] = new Circle(200, 150, 50);
	Shape[2] = new Rectangle(50, 10, 40, 20);
	Shape[3] = new Circle(300, 350, 30);
	Shape[4] = new Circle(100, 50, 5);

	for (int i = 0; Shape[i]; i++) // NULL이 아닐때 까지 루프
		Shape[i]->Draw();

	for (int i = 0; Shape[i]; i++) // NULL이 아닐때 까지 루프
		delete Shape[i];

	return 0;
}