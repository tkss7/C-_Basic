//protected_ColorPoint.cpp
#include<iostream>
using namespace std;

class Point
{
protected: // 상속받은 클래스에서만 바로 접근 할 수 있다. == 쓰지말아야할 누군가가 쓰는걸 막을 수가 없다.
			// private로 선언 후 getx gety 함수를 만들어 꺼내쓰는게 좋다. 
			// 부모클래스의 protected는 private과 같고 자식클래스의 protected는 public과 같다.
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
class ColorPoint : public Point //물려받아도 private멤버는 안됨(메모리만 물려받음?)
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
		if (this->x == ref.x && this->y == ref.y) // x, y 가 protected로 선언되었기에 씀
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

	//cp.x = 100; //외부접근이라 안됨 ==> 상속받은 클래스 안에서만 사용 가능

	ColorPoint cp2;
	cp2.set(10, 20);
	cp2.setColor("Red");

	cout << ((cp.equals(cp2)) ? "Equal" : "Not Equal") << endl;

	return 0;
}