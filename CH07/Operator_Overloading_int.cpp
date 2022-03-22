//Operator_Overloading_int.cpp
#include<iostream>
using namespace std;
/*
	반드시 전역함수로 연산자 오버로딩이 되어야 하는 경우
	1. 첫번째 인자가 this가 아닌 경우
	2. 
*/
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
	friend Point operator+(int n, const Point& ref);
};

Point operator+(int n, const Point& ref)
{
	Point temp(n + ref.x, n + ref.y);
	return temp;
}

int main()
{
	Point p1(1, 1);
						//this : 멤버객체 첫번째 것을 this로 부르지 못할때 전역함수로 작성해야한다.
	Point p2 = 30 + p1; // 30.operator(int) //멤버함수 작성 불가
						//operator+(30,p2) // 전역함수 작성
	p2.showData();

	return 0;
}