//Operator_Overloading3.cpp
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

	Point &operator++()
	{
		this->x++;
		y++;

		return *this;
	}

	friend Point& operator--(Point& ref);

	//p3 = p2++;
	Point operator++(int)
	{
		Point temp(this->x++, this->y++); //���߿� ����
		return temp;
	}

	friend Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)
{
	ref.x--;
	ref.y--;
	return ref;
}
//p4 = p2--;
Point operator--(Point &ref, int)
{
	Point temp(ref.x--, ref.y--);
	return temp;
}

int main()
{
	Point p1(1, 1);

	++p1; // p1.operator++()	//����Լ�
	p1.showData();

	++(++p1); //4
	p1.showData();

	--p1;	//operator--(p1)	//�����Լ�
	p1.showData();
	cout << "====================================" << endl;
	//p1++;	//p1.operator++(int) : ��������
	//++p1;	//p1.operator++()	 : ��������

	Point p2(1, 1);

	Point p3 = p2++; //p2.operator++(int)  == p3�� �ְ��� ++��

	p2.showData(); // 2, 2
	p3.showData(); // 1, 1

	Point p4 = p2--; //p2.operator--(int)
	p2.showData(); // 1, 1
	p4.showData(); // 2, 2

	return 0;
}