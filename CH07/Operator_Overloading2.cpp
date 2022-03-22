//Operator_Overloading2.cpp
#include<iostream>
using namespace std;
/*
	F9 :�ߴ� �� ����
	F5 : ����� ����
	F11 : �Ѵܰ�� �����
	shift + F5 : ����� ����
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
	Point operator+(const Point& ref); //����Լ� ����

	friend Point operator-(const Point& ref1, const Point& ref2); //�����Լ� ����
};
Point Point::operator+(const Point& ref) //����Լ�
{
	Point temp(this->x + ref.x, this->y + ref.y); // ������Ҳ��� const ���°��� ������
	return temp;
}
Point operator-(const Point &ref1, const Point &ref2) //�����Լ�
{
	Point temp(ref1.x - ref2.x, ref1.y - ref2.y);
	return temp;
}

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

						//����Լ��� ����
	Point p3 = p1 + p2; //p1.operator+(p2)
	p3.showData();

						//�����Լ��� ����
	Point p4 = p3 - p1; //operator-(p3, p1)
	p4.showData();
	return 0;
}