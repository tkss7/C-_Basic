//static_Circle.cpp
#include<iostream>
using namespace std;
/*
	���������� CIrcle Ŭ���� ���� �� �Ѱ��� �������
*/
class Circle
{
private:
	int radius; //��� ����
	static int numOfCircles; //��������( Ŭ���� �ȿ��� �����Ǵ� ����)
public:
	Circle(int r=1 )
	{
		radius = r;
		numOfCircles++;
		cout << "Circle(int r =1) ������ : " << radius << ", Circle �� : " << numOfCircles << endl;
	}

	~Circle()
	{
		numOfCircles--;
	}

	int getRadius()
	{
		return radius;
	}

	static int getNumOfCircles() //���� �Լ�(�޼���) : ��ü ������ ���ص� ������� �θ� �� �ִ�. : ���� ��, ���� �� �� �� ����
	{
		return numOfCircles;
	}

};//���� �޼ҵ�� ���������� �θ� �� ����
//�Ϲ� �޼ҵ�� ���� ������ �θ� �� ����
int Circle::numOfCircles = 0; //Circle Ŭ������ �������� �ʱ�ȭ : �ݵ�� �̷������� �������
int main()
{				//���� �޼���� ��������� ������ �� �ִ�.
	cout << "���� Circle �� �� : " << Circle::getNumOfCircles() << endl; //Ŭ���� ��ü�� ����� ���� ���� �����ϴ� ���(�ܺο��� ����)
	Circle* p = new Circle[10];
	
	cout << "���� Circle �� : " << p->getNumOfCircles() << endl; //��ü�� �����ϹǷ� ��ü�� �޼ҵ�ε��� �� ����
	delete[] p;
	cout << "���� Circle �� : " << Circle::getNumOfCircles() << endl;

	Circle a;
	cout << "���� Circle �� : " << a.getNumOfCircles() << endl;

	Circle b;
	cout << "���� Circle �� : " << b.getNumOfCircles() << endl;

	return 0;
}