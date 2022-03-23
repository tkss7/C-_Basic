//protected_ColorPoint.cpp
#include<iostream>
using namespace std;

class Point
{
protected: // ��ӹ��� Ŭ���������� �ٷ� ���� �� �� �ִ�. == �������ƾ��� �������� ���°� ���� ���� ����.
			// private�� ���� �� getx gety �Լ��� ����� �������°� ����. 
			// �θ�Ŭ������ protected�� private�� ���� �ڽ�Ŭ������ protected�� public�� ����.
	int x, y;
public:
	void set(int x, int y)
	{
		this->x = x; this->y = y;
	}

	void showPoint()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
};
class ColorPoint : public Point //�����޾Ƶ� private����� �ȵ�(�޸𸮸� ��������?)
{
private:
	string color;
public:
	ColorPoint() {}
	ColorPoint(string _color)
	{
		color = _color;
	}
	void setColor(string _color)
	{
		color = _color;
	}
	void showColorPoint()
	{
		cout << color << ": ";
		//showPoint();
		cout << "(" << x << "," << y << ")" << endl;
	}

	bool equals(ColorPoint &ref)
	{
		if (this->x == ref.x && this->y == ref.y) // x, y �� protected�� ����Ǿ��⿡ ��
			return true;
		else
			return false;
	}

};

int main()
{
	ColorPoint cp;

	cp.set(10, 20);
	cp.setColor("Red");

	cp.showColorPoint();

	//cp.x = 100; //�ܺ������̶� �ȵ� ==> ��ӹ��� Ŭ���� �ȿ����� ��� ����

	ColorPoint cp2;
	cp2.set(10, 20);
	cp2.setColor("Red");

	cout << ((cp.equals(cp2)) ? "Equal" : "Not Equal") << endl;

	return 0;
}