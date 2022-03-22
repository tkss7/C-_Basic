//Operator_Intro.cpp
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
	Point(int _x = 0, int _y=0)
	{
		x = _x;
		y = _y;
	}

	void showData()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}
	// p2 = p1 + 30;
	Point operator+(int value) //������ �Լ�
	{
		Point temp;

		temp.x = this->x + value;
		temp.y = this->y + value;

		return temp;
	}

	Point(const Point& ref) // ���� ������
	{
		cout << "Point(const Point& ref)" << endl;
		x = ref.x;
		y = ref.y;
	}
};

int main()
{
	Point p1(1, 2);
	p1.showData();

			// operator+(30) : �����ڿ����ε� ���� ��
	Point p2 = p1 + 30; //������ �� ��������� �θ�
	p2.showData();

	return 0;
}