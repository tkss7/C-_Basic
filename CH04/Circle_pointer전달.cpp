#include<iostream> //03/18
using namespace std;
// C++ ����ü�� Class�� �������� ������ ����Ʈ ���� ����ü�� Public , Class�� Private ��� �� ���̴�~
class Circle
{
private:
	int radius=1;
public:
	Circle(){ cout << "Circle()" << radius << endl; }
	Circle(int r)
	{

		radius = r;
		cout << "Circle(int r)" << radius << endl;
	}
	~Circle()
	{
		cout << "~Circle()"<<radius<<endl;
	}
	int getRadius()
	{
		return radius;
	}
	double getArea()
	{
		return radius * radius * 3.15;
	}
};

int main()
{
	Circle donut;

	Circle pizza(30);

	Circle* p = &donut; //��ü����
	cout << "p->getArea()" << p->getArea() << endl;

	p=&pizza;
	cout << "p->getArea()" << p->getArea() << endl;

	return 0;
}