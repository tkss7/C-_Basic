//Circle_New.cpp 03/18
#include<iostream>
using namespace std;
//this-> : ����Ʈ ���� ; ��ü�� �������� �޼ҵ尡 �ϳ��ε� �װ� ���ɱ����ϴ� �ǰ�? == this
/*
	���� int setRadius(int radius)
	{
		radius=radius; ==> ���� �������оȵǴϱ� this->radius=radius �� �ؾ��Ѵ�.
	}

	class Circle  //Ŭ������
{
private:
	int radius; //��� ����
public:
	Circle() :radius(1) { cout << "Circle()" << endl; } //������
	~Circle()  // �Ҹ���
	{
		cout << "~Circle()" << radius << endl;
	}
	int getRadius() { return radius; } //�޼ҵ�

	int main()
	Circle c1(5); //��ü ���� or ��ü
*/
class Circle
{
private:
	int radius;
public:
	Circle() :radius(1) { cout << "Circle()" << endl; }
	Circle(int r)
	{

		this->radius = r;
		cout << "Circle(int r)" << radius << endl;
	}
	~Circle()
	{
		cout << "~Circle()" << radius << endl;
	}
	Circle(const Circle& c) // ���� �����ڷ� �����ϸ� �̰� �������ص� ����Ʈ ������ ����.
	{
		this->radius = c.radius;
		cout << "Circle(const Circle &c)" <<radius <<endl;
	}
	int getRadius() { return radius; }
	int setRadius(int r)
	{
		this->radius = r;
		return radius;
	}
	double getArea() { return radius * radius * 3.15; }

};

int main()
{
	Circle c1(5); //��ü ����;
	Circle* p1 = new Circle;
	Circle* p2 = new Circle;;
	
	Circle* p3;
	p3 = new Circle(10);
	p3->setRadius(25);

	cout << p1->getRadius() << endl;
	cout << p2->getRadius() << endl;
	cout << p3->getRadius() << endl;

	Circle* p4 = &c1;
	cout << p4->getRadius() << endl;

	Circle* p5 = new Circle(c1); //���� ������ : c1�� �����Ͽ� �����Ҵ���� Circle�� ��ü�� �����Ѵ�.

	cout << p5->getRadius() << endl;

	delete p1;
	delete p2; 
	delete p3;
	delete p5;


	return 0;
}
/*
	���� ������ : ���� ����� ���� ����� ����
		�������� : �����͸� ��� �� ��� ������ ��ü�� ����� ��ü�� name�� ���ÿ� ���� �ּҸ� ����Ŵ
		-> ������ ���� �����ϸ� ������ ���ʵ� �����,
		->���߿� �����Ҵ� �޸� ��ȯ�������� ���� ���� �ι� ��ȯ�ϹǷ� ������ ������

		�������� : �����͸� ����ص� ���ڿ��� �����ϰ� ����� ��ü���� �����Ҵ�� ������ ���ڿ��� �����ϹǷ�
		��������� ���� ������ �������ʴ´�.
		-> ���ڿ� ���̸�ŭ �����Ҵ� �Ͽ� �迭����� ��ü�� ����� ���� -> strcpy�� �̿��� ���ڿ�����
*/