//Copy_Constructor.cpp
#include<iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point()
	{
		cout << "Point()" << endl;
	}
	Point(int _x, int _y)
	{
		cout << "Point(int _x, int _y)" << endl;
		x = _x, y = _y;
	}
	Point(const Point& ref) //복사생성자 아예 안만들면 디폴트 복사생성자가 생성됨
	{ //const 쓴 이유 : 도중에 값을 변경하지 않고 복사만 한다는걸 보증하는 의미
		cout << "Point(const Point &ref)" << endl;
		this->x = ref.x;
		this->y = ref.y;
	}
	void showData()
	{
		cout << x << ", " << y << endl;
	}
};

int main()
{
	Point p1(10, 20);
	
	Point p2(p1); //Point p2 = p1;
	p2.showData();


	return 0;
}