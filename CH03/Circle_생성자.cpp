//Circle_������.cpp 03/17
#include<iostream>
//�����ڰ� ���� �ҷ����� �׿� ���� �޸𸮰� �Ҵ�ȴ�.
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
	cout << "������ : " << donut.getRadius() << endl;

	Circle pizza(30);
	cout << "������ : " << pizza.getRadius() << endl;
	cout << "===================" << endl;

	Circle c1; //���ȣ ������ Circle()
	Circle c2(1); // �������� �����ִ� ������ Circle(int r)
	Circle c3 =  Circle(); //������ ����� ȣ��, Circle()
	Circle c4 =  Circle(3); // �������� �����ִ� ������ ����� ȣ��, Circle(int r)

	Circle c5(); // �Լ� ���� // c5��� �μ��� �� �޴� return�� Circle�� �Լ� ����




	return 0;
}