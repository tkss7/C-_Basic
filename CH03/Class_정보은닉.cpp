//Class_��������.cpp 03/17
#include<iostream>
using namespace std;

class Point
{
private: //private�� �����ϴ� ���� : �Է� ������ ���� �ϱ� ���ؼ�
	int x, y; // 1~100 ���̸� ����
public:
	int getX() { return x; }
	int getY() { return y; }

	bool setX(int num) 
	{
		if (num <= 0 || num > 100)
		{
			cout << "x ��ǥ ����, ��ǥ�� 1~100 ���� Ȯ��." << endl;
			return false;
		}
		x = num;
		return true;
	}
	bool setY(int num) 
	{
		if (num <= 0 || num > 100)
		{
			cout << "y ��ǥ ����, ��ǥ�� 1~100 ���� Ȯ��." << endl;
			return false;
		}
		y = num;
		return true;
	}
	void shwXY()
	{
		cout << "��ǥ x: " << x << ", ��ǥ y : " << y << endl;
	}
};
class A
{
public:
	void print(Point &refP)
	{
		cout << "Class A print((Point &refP) " << endl;
		refP.shwXY();
	} // �̷��� ����°� ĸ��ȭ�� ����ȴ�. // �ε����� ��찡 �ƴ϶�� ���� �޼ҵ�� �ϳ��� Ŭ�������� ��������!!
};
int main()
{
	int x, y;
	cout << "��ǥx,y ? ";
	cin >> x >> y; //10, 30

	Point p1;
	if (p1.setX(x) && p1.setY(y))
	{
		cout << "�Էµ� ��ǥ�� ����Ͽ� image �۾�����." << endl;
		//p1.shwXY();
		cout << "x : " << p1.getX() << ", y : " << p1.getY() << endl;
	}
	else
	{
		cout << "��ǥ�� �ٸ��� �ʽ��ϴ�." << endl;
		p1.shwXY();
	}
	A tmp;
	tmp.print(p1);
	

	return 0;
}