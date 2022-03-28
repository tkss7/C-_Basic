//Template_Point_Class.cpp
#include<iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T x, y;
public:
	Point(T _x = 0, T _y = 0)
	{
		x = _x, y = _y;
	}

	void showData()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}
};

template <typename T>
void swapData(T &x, T &y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	Point<int> p1(10, 20);
	Point<int> p2(100, 200);

	swapData(p1, p2);

	p1.showData();
	p2.showData();
	cout << endl;

	Point<double> p3(1.1, 1.2);
	Point<double> p4(10.1, 10.2);

	swapData(p3, p4);

	p3.showData();
	p4.showData();

	return 0;
}