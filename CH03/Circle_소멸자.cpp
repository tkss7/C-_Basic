//Circle_�Ҹ���.cpp 03/18
#include<iostream>
#include<vld.h>
using namespace std;
class Circle {
private:
	int radius;
public:
	Circle() // ������ : �ַ� ��� �ʱ�ȭ�� �ϴ°� ������
	{
		cout << "Circle()" << endl;
		radius = 0;
	}
	~Circle() //�Ҹ���, ��ü�Ҹ� �� ����
	{
		cout << "~Circle() : " << radius << endl;
	}
	Circle(int r) // ������ ���ڷ� �޴� ������
	{
		cout << "Circle(int r)" << endl;
		radius = r;
	}
	int getRadius()
	{
		return radius;
	}
	double getArea();

};
double Circle::getArea() // �̷��� �ϸ� Ŭ���� �ۿ� �־  ��Ŭ Ŭ���� �ȿ� �ִ� �޼ҵ��� �ν���
{
	return radius * radius * 3.15;
}
int main()
{
	Circle donut; //��ü�� ������ ���ÿ� ������ ȣ��
	Circle pizza(30);

	return 0;
}