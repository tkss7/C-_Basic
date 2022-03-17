//Circle_생성자3.cpp 03/17
#include<iostream>
using namespace std;
class Circle {
	// 디폴트 생성자는, 사용자정의 생성자가 없을 때 호출된다.
	// 처음 생성되고 초기화 안하면 쓰레기 값을 갖고있다.
private:
	int radius;
public:
	Circle() // 디폴트 생성자는, 사용자정의 생성자가 없을 때 호출된다.
	{
		cout << "Circle()" << endl;
	}
	Circle(int r) 
	{
		cout << "Circle(int r)" << endl;
		radius = r;
	}
	int getRadius()
	{
		return radius;
	}
};
int main()
{
	Circle donut(10); //객체는 생성과 동시에 생성자 호출
	cout << "반지름 : " << donut.getRadius() << endl;

	Circle pizza;
	cout << "반지름 : " << pizza.getRadius() << endl;

	return 0;
}