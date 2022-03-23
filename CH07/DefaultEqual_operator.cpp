//DefaultEqual_operator.cpp
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

	void showData()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}

	Point(const Point& ref) //���� ������
	{
		cout << "Point(const Point &ref)" << endl;
		x = ref.x;
		y = ref.y;
	}

	Point& operator=(const Point &ref) //���� ������ == Point& operator : ���� Point�� &�� ������ ��������ڰ� �ҷ�����.
	{
		x = ref.x;
		y = ref.y;
		cout << "operator=(const Point &ref)" << endl;
		return *this;
	}

};
int main()
{
	Point p1(1, 5);
	Point p2(p1); //���������, ��ü�� ������ ���ÿ� ��ü�� ���� �� ȣ��

	p1.showData();
	p2.showData();

	Point p3;
	p3 = p1; // ����Ʈ ���Կ����� �޼��� ����, ��ü�� ���Թ����� ��ü�� ���Թ��� �� ȣ��
			//p3.operator=(p1)
	p3.showData();
	cout << "====================" << endl;
	Point p4, p5;
	p5 = p4 = p1;
	p4.showData();
	p5.showData();

	return 0;
}