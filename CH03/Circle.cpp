//Circle.cpp 03/17
#include<iostream>
using namespace std;
// �Ϲ����� ���´� Ŭ�����ȿ� ���� �ϰ� Ŭ���� �ۿ� ::�� ����ؼ� ����
class Circle {
public:
	int radius;

	int GetRadius()
	{
		return radius;
	}
	double GetArea();  // �ݵ�� �����ؾ� �޼ҵ� �ν�
};
double Circle::GetArea() // �̷��� �ϸ� Ŭ���� �ۿ� �־  ��Ŭ Ŭ���� �ȿ� �ִ� �޼ҵ��� �ν���
{
	return radius * radius * 3.15;
}
int main()
{
	Circle donut;

	donut.radius = 1;
	cout << "������ : " << donut.GetRadius() << endl;

	double area = donut.GetArea();
	cout << "���� : " << donut.GetArea() << endl;

	Circle pizza;
	pizza.radius = 5;
	cout << "���� : " << pizza.GetArea() << endl;
	return 0;
}