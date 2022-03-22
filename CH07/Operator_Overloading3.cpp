//Operator_Overloading3.cpp
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

	Point &operator++()
	{
		this->x++;
		y++;

		return *this;
	}

	friend Point& operator--(Point& ref);

	//p3 = p2++;
	Point operator++(int)
	{
		Point temp(this->x++, this->y++); //나중에 증가
		return temp;
	}

	friend Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)
{
	ref.x--;
	ref.y--;
	return ref;
}
//p4 = p2--;
Point operator--(Point &ref, int)
{
	Point temp(ref.x--, ref.y--);
	return temp;
}

int main()
{
	Point p1(1, 1);

	++p1; // p1.operator++()	//멤버함수
	p1.showData();

	++(++p1); //4
	p1.showData();

	--p1;	//operator--(p1)	//전역함수
	p1.showData();
	cout << "====================================" << endl;
	//p1++;	//p1.operator++(int) : 후위연산
	//++p1;	//p1.operator++()	 : 전위연산

	Point p2(1, 1);

	Point p3 = p2++; //p2.operator++(int)  == p3에 주고나서 ++함

	p2.showData(); // 2, 2
	p3.showData(); // 1, 1

	Point p4 = p2--; //p2.operator--(int)
	p2.showData(); // 1, 1
	p4.showData(); // 2, 2

	return 0;
}