//Operator_Overloading_int.cpp
#include<iostream>
using namespace std;
/*
	�ݵ�� �����Լ��� ������ �����ε��� �Ǿ�� �ϴ� ���
	1. ù��° ���ڰ� this�� �ƴ� ���
	2. 
*/
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
	friend Point operator+(int n, const Point& ref);
};

Point operator+(int n, const Point& ref)
{
	Point temp(n + ref.x, n + ref.y);
	return temp;
}

int main()
{
	Point p1(1, 1);
						//this : �����ü ù��° ���� this�� �θ��� ���Ҷ� �����Լ��� �ۼ��ؾ��Ѵ�.
	Point p2 = 30 + p1; // 30.operator(int) //����Լ� �ۼ� �Ұ�
						//operator+(30,p2) // �����Լ� �ۼ�
	p2.showData();

	return 0;
}