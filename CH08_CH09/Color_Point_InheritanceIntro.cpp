//Color_Point_InheritanceIntro.cpp //Inheritance == ���
#include<iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	void set(int x, int y)
	{
		this->x = x; this->y = y;
	}

	void showPoint()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
};
class ColorPoint : public Point //�����޾Ƶ� private����� �ȵ�(�޸𸮸� ��������?)
{
private:
	string color;
public:
	ColorPoint() {}
	ColorPoint(string _color)
	{
		color = _color;
	}
	void setColor(string _color)
	{
		color = _color;
	}
	void showColorPoint()
	{
		cout << color << ": ";
		showPoint();
	}
};
int main()
{
	ColorPoint cp;

	cp.set(10, 20);
	cp.setColor("Red");

	cp.showColorPoint();

	return 0;
}