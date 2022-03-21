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
	Point(const Point& ref) //��������� �ƿ� �ȸ���� ����Ʈ ��������ڰ� ������
	{ //const �� ���� : ���߿� ���� �������� �ʰ� ���縸 �Ѵٴ°� �����ϴ� �ǹ�
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