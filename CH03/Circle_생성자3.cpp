//Circle_������3.cpp 03/17
#include<iostream>
using namespace std;
class Circle {
	// ����Ʈ �����ڴ�, ��������� �����ڰ� ���� �� ȣ��ȴ�.
	// ó�� �����ǰ� �ʱ�ȭ ���ϸ� ������ ���� �����ִ�.
private:
	int radius;
public:
	Circle() // ����Ʈ �����ڴ�, ��������� �����ڰ� ���� �� ȣ��ȴ�.
	{
		cout << "Circle()" << endl;
	}
	Circle(int r) 
	{
		cout << "Circle(int r)" << endl;
		radius = r;
	}
	int getRadius()
	{
		return radius;
	}
};
int main()
{
	Circle donut(10); //��ü�� ������ ���ÿ� ������ ȣ��
	cout << "������ : " << donut.getRadius() << endl;

	Circle pizza;
	cout << "������ : " << pizza.getRadius() << endl;

	return 0;
}