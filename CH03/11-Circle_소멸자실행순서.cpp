//11-Circle_�Ҹ��ڽ������.cpp 03/18
#include <iostream> 
using namespace std; 

//�����Ҹ��� ���� �ݴ�� ����

class Circle
{
public:
	int radius;
	Circle(); 
	Circle(int r);
	~Circle(); 
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "������ " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "Circle(int r) : " << radius <<  endl;
}

Circle::~Circle() { // �Ҹ���, ��ü �Ҹ� �� ����(�ڿ��ݳ�) ��������� �Ҹ��ڰ� ������ ���ȣ�� �ڵ� �����ȴ�.
	cout << "~Circle() :" << radius << " �Ҹ�" << endl;
}

double Circle::getArea()  //����޼���
{
	return 3.14*radius*radius;
}

//���� ��ü���� ������ ���׸�Ʈ�� �Ҵ� -> ���� ����
Circle globalDonut(1000);    //1
Circle globalPizza(2000);    //2

void f() //�����Լ�
{
	Circle fDonut(100);    //5
	Circle fPizza(200);    //6
}

int main()
{
	Circle mainDonut;       //3
	Circle mainPizza(30);   //4

	f();
	// �Ҹ��� �Ҵ���� �������� �Ҹ�ȴ�. 

	return 0;
}
