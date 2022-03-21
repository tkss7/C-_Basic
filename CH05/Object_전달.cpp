//Object_����.cpp

#include<iostream>
using namespace std;

class Circle
{
private:
	int radius;
public:
	Circle() { cout << "Circle()\n"; }
	Circle(int r)
	{
		cout << "Circle(int r)\n";
		radius = r;
	}
	//Circle(Circle &cir) {
	//	cout << "Circle(Circle &cir)\n";
	//	this->radius = cir.radius;
	//}
	~Circle() { cout << "~Circle()" << radius << endl; }
	int getRadius()
	{
		return radius;
	}
	void setRadius(int r)
	{
		radius = r;
	}
	double getArea()
	{
		return radius * radius * 3.15;
	}
};
void Increse1(Circle cir)
{
	int r = cir.getRadius();
	cir.setRadius(r + 1);

}
void Increse2(Circle *cirP)
{
	int r = cirP->getRadius();
	cirP->setRadius(r + 1);

}
Circle Increse3()
{
	Circle tmp; //��� �Լ� ������ �Ҹ�Ǹ� �Ҹ������� ��ü ��ȯ��
	tmp.setRadius(20);

	return tmp;

}
void Increse4(Circle &cir)
{
	int r = cir.getRadius();
	cir.setRadius(r + 1);

}
int main()
{
	Circle waffle(30);

	Increse1(waffle); //call by value
	cout << waffle.getRadius() << endl;

	Increse2(&waffle); //call by reference
	cout << waffle.getRadius() << endl;

	Circle pizza = Increse3(); //��ü ��ȯ
	cout << "pizza.getRadius() :" << pizza.getRadius() << endl;

	Circle donut = pizza; //��ü ����
	cout << "donut.getRadius() :" << donut.getRadius() << endl;

	Increse4(waffle); //31�� ��������


	return 0;
}