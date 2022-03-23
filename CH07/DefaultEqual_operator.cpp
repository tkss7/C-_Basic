//DefaultEqual_operator.cpp
#include<iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0)
	{
		x = _x, y = _y;
	}

	void showData()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}

	Point(const Point& ref) //복사 생성자
	{
		cout << "Point(const Point &ref)" << endl;
		x = ref.x;
		y = ref.y;
	}

	Point& operator=(const Point &ref) //대입 연산자 == Point& operator : 만약 Point에 &가 없으면 복사생성자가 불려진다.
	{
		x = ref.x;
		y = ref.y;
		cout << "operator=(const Point &ref)" << endl;
		return *this;
	}

};
int main()
{
	Point p1(1, 5);
	Point p2(p1); //복사생성자, 객체가 생성과 동시에 객체를 받을 때 호출

	p1.showData();
	p2.showData();

	Point p3;
	p3 = p1; // 디폴트 대입연산자 메서드 실행, 객체가 대입문으로 객체를 대입받을 때 호출
			//p3.operator=(p1)
	p3.showData();
	cout << "====================" << endl;
	Point p4, p5;
	p5 = p4 = p1;
	p4.showData();
	p5.showData();

	return 0;
}