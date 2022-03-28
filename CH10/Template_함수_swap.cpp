//Template_ÇÔ¼ö_swap.cpp
#include<iostream>
using namespace std;

class Circle
{
private:
	int radius;
public:
	Circle():radius(0) {}
	Circle(int r)
	{
		radius = r;
	}
	int getRadius()
	{
		return radius;
	}
};


template <typename T>
void myswap(T &x, T &y)
{
	T tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

int main()
{

	int a = 10 , b = 20;

	myswap(a, b);
	cout << "a : " << a << ", b : " << b << endl;
	
	double d1 = 1.5, d2 = 5.9;
	myswap(d1, d2);
	cout << "d1 : " << d1 << ", d2: " << d2 << endl;

	Circle donut(30), pizza(50);
	myswap(donut, pizza);


	cout << "donut.getRadius() : " << donut.getRadius() << endl;
	cout << "pizza.getRadius() : " << pizza.getRadius() << endl;
}