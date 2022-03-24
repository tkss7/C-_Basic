//Point_출력스트림연산.cpp 03/24
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
	friend ostream& operator<<(ostream& os, Point& ref);
};

ostream& operator<<(ostream& os, Point &ref)
{
	os << ref.x << " , " << ref.y;
	return os;
}

int main()
{
	Point p1(3,5);
	//cout.operator << (p1) // 멤버함수로 못부름
	//operator << (cout, p1) // 전역함수로 불러야함
	cout << "p1 : " << p1 << endl;


	return 0;
}