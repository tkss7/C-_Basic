//Circle_Array.cpp
#include<iostream>
using namespace std;

class Circle
{
private:
	int radius ;
public:
	Circle():radius(1) { cout << "Circle()" << endl; }
	Circle(int r)
	{
		cout << "Circle(int r)" << endl;
		radius = r;
	}
	~Circle()
	{
		cout << "~Circle()\n";
	}
	int getRadius(){return radius;}
	int setRadius(int r)
	{
		radius = r;
		return radius;
	}
	double getArea(){return radius * radius * 3.15;}
};

int main()
{
	Circle circleArray[3];// ���ȣ ������ 3�� ������ , : ��ü�迭

	circleArray[0].setRadius(10);
	(*(circleArray+1)).setRadius(20); //��ü�� ���������� *(ptr+i)�� �Ұ�ȣ�� �ѹ� �� ��������Ѵ�. == (*(ptr+i))
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
		cout << circleArray[i].getRadius() << endl;

	Circle* p = circleArray;
	for (int i = 0; i < 3; i++)
	{
		cout << "���� : " << p->getArea() << endl;
		p++;
	}
	cout << "=============================\n";

	Circle c1[2]; //���ȣ������ 2�� �θ�
	Circle c2[3] = { 1,2,3 };//�ʱ�ȭ�� �Ͼ �� == circle(int) ������ 3�� �θ� // �����ڸ� �ҷ��� �ʱ�ȭ �ϴ°��� �� �����ϴ�.
	// ex) Circle c2[3] = { Circle(1),Circle(2),Circle(3) };

	return 0;
}