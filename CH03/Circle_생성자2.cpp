//Circle_������2.cpp 03/17
#include<iostream>
using namespace std;
class Circle {
private:
	int radius;
public:
	Circle() :Circle(5) //�̿� ������ ȣ�� : ������ �� ���ڸ� ����� �����ε��� �޼��带 ȣ���ϰ� ���ƿ´�. -> �̿� ������ ���� ȣ�� �� �ڱ� �� ȣ��
	{
		cout << "Circle()" << endl;
	}
	Circle(int r) : radius(r) //�ݷ� �ʱ�ȭ radius(r) == radius = r; // radius(r)�� �ӵ��� �� �� ������
		//�ݷ��ʱ�ȭ�� �����ڸ� ��� ���� , �̿� �����ڸ� ȣ���ϴ°� �ƴ϶� ���� �ִ°���.
	{
		cout << "Circle(int r)" << endl;
		//radius = r;
	}
	int getRadius()
	{
		return radius;
	}
};
int main()
{
	Circle donut; //��ü�� ������ ���ÿ� ������ ȣ��
	cout << "������ : " << donut.getRadius() << endl;

	Circle pizza(30);
	cout << "������ : " << pizza.getRadius() << endl;

	return 0;
}