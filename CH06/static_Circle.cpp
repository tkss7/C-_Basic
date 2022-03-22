//static_Circle.cpp
#include<iostream>
using namespace std;
/*
	정적변수는 CIrcle 클래스 안의 딱 한개만 만들어짐
*/
class Circle
{
private:
	int radius; //멤버 변수
	static int numOfCircles; //정적변수( 클래스 안에서 공유되는 변수)
public:
	Circle(int r=1 )
	{
		radius = r;
		numOfCircles++;
		cout << "Circle(int r =1) 반지름 : " << radius << ", Circle 수 : " << numOfCircles << endl;
	}

	~Circle()
	{
		numOfCircles--;
	}

	int getRadius()
	{
		return radius;
	}

	static int getNumOfCircles() //정적 함수(메서드) : 객체 생성을 안해도 상관없이 부를 수 있다. : 생성 전, 생성 후 둘 다 가능
	{
		return numOfCircles;
	}

};//정적 메소드는 정적변수만 부를 수 있음
//일반 메소드는 정적 변수도 부를 수 있음
int Circle::numOfCircles = 0; //Circle 클래스의 정적변수 초기화 : 반드시 이런식으로 해줘야함
int main()
{				//정적 메서드는 정적멤버만 접근할 수 있다.
	cout << "현재 Circle 의 수 : " << Circle::getNumOfCircles() << endl; //클래스 객체가 만들어 지기 전에 접근하는 방법(외부에서 접근)
	Circle* p = new Circle[10];
	
	cout << "현재 Circle 수 : " << p->getNumOfCircles() << endl; //객체가 존재하므로 객체의 메소드로도쓸 수 있음
	delete[] p;
	cout << "현재 Circle 수 : " << Circle::getNumOfCircles() << endl;

	Circle a;
	cout << "현재 Circle 수 : " << a.getNumOfCircles() << endl;

	Circle b;
	cout << "현재 Circle 수 : " << b.getNumOfCircles() << endl;

	return 0;
}