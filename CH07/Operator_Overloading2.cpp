//Operator_Overloading2.cpp
#include<iostream>
using namespace std;
/*
	F9 :중단 점 지정
	F5 : 디버깅 시작
	F11 : 한단계식 디버깅
	shift + F5 : 디버깅 중지
*/
class Point
{
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}

	void showData()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}
	Point operator+(const Point& ref); //멤버함수 선언

	friend Point operator-(const Point& ref1, const Point& ref2); //전역함수 선언
};
Point Point::operator+(const Point& ref) //멤버함수
{
	Point temp(this->x + ref.x, this->y + ref.y); // 변경안할꺼면 const 쓰는것을 권장함
	return temp;
}
Point operator-(const Point &ref1, const Point &ref2) //전역함수
{
	Point temp(ref1.x - ref2.x, ref1.y - ref2.y);
	return temp;
}

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

						//멤버함수로 구현
	Point p3 = p1 + p2; //p1.operator+(p2)
	p3.showData();

						//전역함수로 구현
	Point p4 = p3 - p1; //operator-(p3, p1)
	p4.showData();
	return 0;
}