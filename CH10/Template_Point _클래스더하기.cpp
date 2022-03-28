//Template_Point _Ŭ�������ϱ�.cpp
#include<iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T x, y;
public:
	Point(T _x = 0, T _y = 0)
	{
		x = _x, y = _y;
	}

	Point(const Point& ref)
	{
		cout << "Point(const Point& ref)" << endl;
		x = ref.x;
		y = ref.y;
	}

	void showData()
	{
		cout << "x : " << x << ", y : " << y << endl;
	}
	Point operator+(const Point& ref)
	{
		cout << "Point operator+(const Point& ref)" << endl;
		return Point(x + ref.x, y + ref.y);
	}
	void operator=(const Point& ref) //Ŭ���� ����� �����Ҵ��� �ް� �ִ°� �ִٸ� �������Ұ� : ���������, ������
	{
		cout << "Point operator=(const Point& ref)" << endl;
		x = ref.x;
		y = ref.y;

		
	}

};



template <typename T>
T Add(T ref1, T ref2) // �̷��� ��ü ��ȯ�� ��������� �ҷ��� , ���� &ref�� �ϸ� �Ⱥҷ�������?
{
	T temp; // ������
	temp = ref1 + ref2; // + ������ -> ���� ������
	return temp; //��ü�� �Ķ���ͷ� �Ѿ�� ��������ڰ� �ҷ�����. // ���� ������
}

//template <typename T>
//T Add(T ref1, T ref2) // �̷��� ��ü ��ȯ�� ��������� �ҷ��� , ���� &ref�� �ϸ� �Ⱥҷ�������?
//{
//	return  ref1 + ref2; + ������
//}


int main()
{
	Point<int> p1(1, 1);
	Point<int> p2(2, 2);
	
	Point<int>p3 = Add(p1, p2); // ��������� 2�� , Add���� +������ �ѹ�
	p3.showData();
	cout<<"==========================\n";
	Point<int> p7;
	p7 = p1; //p7.operator=(p1);
	p7.showData();

	cout << "==========================\n";
	Point<double> p4(1.1, 1.1);
	Point<double> p5(2.1, 2.1);

	Point<double>p6 = Add(p4, p5);
	p6.showData();

	return 0;
}