//Point_��½�Ʈ������
#include<iostream>
using namespace std;


class Point
{
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0)
	{
		x = _x, y = _y;
	}
	friend ostream& operator<<(ostream& os, Point& ref);

	friend istream& operator>>(istream& is, Point& ref);
};

ostream& operator<<(ostream& os, Point& ref)
{
	os << ref.x << " , " << ref.y;
	return os;
}

istream& operator>>(istream& is, Point& ref)
{
	cout << "x : ";
	is >> ref.x;
	cout << "y : ";
	is >> ref.y;
	//is >> ref.x >> ref.y;
	//cout << endl;
	return is;
}

int main()
{
	Point p1;

	//cout << "�� ������ �Է��Ͻÿ� : ";
	cin >> p1; // �̷������� ���� ��
	cout << p1;
	cout << "=======================\n";
	Point p2,p3;

	cin >> p2 >> p3;
	cout << p2 << p3;

	return 0;
}