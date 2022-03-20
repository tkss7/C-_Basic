//Circle_NewArray.cpp
#include<iostream>
using namespace std;

class Circle
{
private:
	int radius;
public:
	Circle() :radius(1) { cout << "Circle()" << endl; }
	Circle(int r)
	{
		cout << "Circle(int r)" << endl;
		radius = r;
	}
	~Circle()
	{
		cout << "~Circle()" << radius << endl;
	}
	int getRadius() { return radius; }
	int setRadius(int r)
	{
		radius = r;
		return radius;
	}
	double getArea() { return radius * radius * 3.15; }
};
//N ���� ��ŭ Circle �迭�� �������� �Ҵ�ް�, �������� �Է¹޴´�. �׸��� ��ü�迭�� ����� �ּ� ��ȯ
Circle* funCircle(int n)
{
	Circle* p = new Circle[n];
	int R;

	for (int i = 0; i < n; i++)
	{
		cout << "������ : ";
		cin >> R;
		(p + i)->setRadius(R); // ??
	}
	return p;
}

int main()
{
	int N;
	cout << " ������ Circle ���� ?";
	cin >> N; // 3

	Circle* CircleP = funCircle(N);

	for (int i = 0; i < N; i++)
	{
		cout << "Circle " << i << "���� ���� : " << CircleP[i].getArea() << endl;
	}

	//�޸� ����
	delete[] CircleP;


	return 0;
}