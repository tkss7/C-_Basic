//Operator_Intro.cpp
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
	Point(int _x = 0, int _y=0)
	{
		x = _x;
		y = _y;
	}

	void showData()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}
	// p2 = p1 + 30;
	Point operator+(int value) //연산자 함수
	{
		Point temp;

		temp.x = this->x + value;
		temp.y = this->y + value;

		return temp;
	}

	Point(const Point& ref) // 복사 생성자
	{
		cout << "Point(const Point& ref)" << endl;
		x = ref.x;
		y = ref.y;
	}
};

int main()
{
	Point p1(1, 2);
	p1.showData();

			// operator+(30) : 연산자오버로딩 구현 식
	Point p2 = p1 + 30; //대입할 때 복사생성자 부름
	p2.showData();

	return 0;
}