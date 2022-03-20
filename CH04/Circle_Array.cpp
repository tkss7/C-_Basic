//Circle_Array.cpp
#include<iostream>
using namespace std;

class Circle
{
private:
	int radius ;
public:
	Circle():radius(1) { cout << "Circle()" << endl; }
	Circle(int r)
	{
		cout << "Circle(int r)" << endl;
		radius = r;
	}
	~Circle()
	{
		cout << "~Circle()\n";
	}
	int getRadius(){return radius;}
	int setRadius(int r)
	{
		radius = r;
		return radius;
	}
	double getArea(){return radius * radius * 3.15;}
};

int main()
{
	Circle circleArray[3];// 빈괄호 생성자 3개 생성됨 , : 객체배열

	circleArray[0].setRadius(10);
	(*(circleArray+1)).setRadius(20); //객체는 포인터형식 *(ptr+i)에 소괄호로 한번 더 묶어줘야한다. == (*(ptr+i))
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
		cout << circleArray[i].getRadius() << endl;

	Circle* p = circleArray;
	for (int i = 0; i < 3; i++)
	{
		cout << "면적 : " << p->getArea() << endl;
		p++;
	}
	cout << "=============================\n";

	Circle c1[2]; //빈괄호생성자 2번 부름
	Circle c2[3] = { 1,2,3 };//초기화가 일어난 것 == circle(int) 생성자 3번 부름 // 생성자를 불러서 초기화 하는것이 더 안전하다.
	// ex) Circle c2[3] = { Circle(1),Circle(2),Circle(3) };

	return 0;
}