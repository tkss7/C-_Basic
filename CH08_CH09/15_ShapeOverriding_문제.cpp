//15_ShapeOverriding_����.cpp 03/24

/*
�Ϲ����� ������ �ǹ��ϴ� Point(��ǥ�� ����)Ŭ������ �簢���� �ǹ��ϴ� 
Rectangle(��ǥ,����,����) Ŭ����, ���� �ǹ��ϴ� Circle(��ǥ,������)Ŭ������ �����Ѵ�.
�簢���� ���� ������ �����̹Ƿ� PointŬ������ ��Ӱ��踦 �����Ѵ�.
���� main() �Լ��� �����Ͽ� ������ ����� ����Ѵ�.

������
[Rectangle] Position = ( 200, 100) Size = ( 50, 50)
[Circle] Position = ( 300, 100) Radius = 30

===================
[Rectangle] Position = ( 200, 100) Size = ( 50, 50)
[Circle] Position = ( 200, 150) Radius = 50
[Rectangle] Position = ( 50, 10) Size = ( 40, 20)
*/

#include <iostream>
using namespace std;
#include<vld.h>
// �Ϲ����� '����'�� ��¡�ϴ� Ŭ����
class Point //�߻� Ŭ����
{
protected:
	double xpos, ypos;
public:
	Point()
	{
		xpos = ypos = 0.0;
	}
	Point(double _x, double _y) 
	{
		xpos = _x;
		ypos = _y;
	}
	//virtual void Draw() const {}; //�����Լ�
	virtual void Draw() const = 0; //���� �����Լ� : ��ɱ����� ���� �ʴ� �Ǽ��� ������ �ʴ� ����?�� ���ش�.
};


// �簢���� ��¡�ϴ� Ŭ����
class Rectangle : public Point
{
private:
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double _x, double _y, double _width, double _height);

	void Draw() const;
};

Rectangle::Rectangle():Point()
{
	width = height = 100.0f;
}

//������ ����
Rectangle::Rectangle(double _x, double _y, double _width, double _height):Point(_x, _y)
{
	width = _width;
	height = _height;
}

//�޼��� �߰�
void Rectangle::Draw() const
{
	cout << "[Rectangle] Position = (" << xpos <<"," << ypos << ") Size = (" << width <<"," << height << ")" << endl;
}

// ���� ��¡�ϴ� Ŭ����
class Circle : public Point
{
private:
	double radius;
public:
	Circle();
	Circle(double _x, double _y, double _radius);

	void Draw() const;
};

Circle::Circle():Point()
{
	radius = 100.0f;
}

//������ ����
Circle::Circle(double _x, double _y, double _radius):Point(_x, _y)
{
	radius = _radius;
}

//�޼��� �߰�
void Circle::Draw() const
{
	cout << "[Circle] Position = (" << xpos <<"," << ypos << ") Radius = " << radius << endl;
	
}

int main()
{
	/*
	// �簢�� ��ü ���� �� �׸���
	Rectangle r(200, 100, 50, 50);
	r.Draw();

	// �� ��ü ���� �� �׸���
	Circle c(300, 100, 30);
	c.Draw();
	cout << endl; // ��������� virtual�� �ʿ� ������

	cout << "===================" << endl;
	Point* p1 = new Rectangle(200, 100, 50, 50);
	p1->Draw();
	Point* p2 = new Circle(200, 150, 50);
	p2->Draw();
	Point* p3 = new Rectangle(50, 10, 40, 20);
	p3->Draw();
*/
	Point* Shape[10] = { NULL };
	//Point* Sape = new Point; // �߻�Ŭ�����̹Ƿ� ���Ŭ���� ��ü ���� ����
	//Point* Sape = new Rectangle(200, 100, 50, 50);

	Shape[0] = new Rectangle(200, 100, 50, 50);
	Shape[1] = new Circle(200, 150, 50);
	Shape[2] = new Rectangle(50, 10, 40, 20);
	Shape[3] = new Circle(300, 350, 30);
	Shape[4] = new Circle(100, 50, 5);

	for (int i = 0; Shape[i]; i++) // NULL�� �ƴҶ� ���� ����
		Shape[i]->Draw();

	for (int i = 0; Shape[i]; i++) // NULL�� �ƴҶ� ���� ����
		delete Shape[i];

	return 0;
}