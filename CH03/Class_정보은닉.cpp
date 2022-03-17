//Class_정보은닉.cpp 03/17
#include<iostream>
using namespace std;

class Point
{
private: //private로 선언하는 이유 : 입력 범위를 설정 하기 위해서
	int x, y; // 1~100 사이만 저장
public:
	int getX() { return x; }
	int getY() { return y; }

	bool setX(int num) 
	{
		if (num <= 0 || num > 100)
		{
			cout << "x 좌표 오류, 좌표는 1~100 사이 확인." << endl;
			return false;
		}
		x = num;
		return true;
	}
	bool setY(int num) 
	{
		if (num <= 0 || num > 100)
		{
			cout << "y 좌표 오류, 좌표는 1~100 사이 확인." << endl;
			return false;
		}
		y = num;
		return true;
	}
	void shwXY()
	{
		cout << "좌표 x: " << x << ", 좌표 y : " << y << endl;
	}
};
class A
{
public:
	void print(Point &refP)
	{
		cout << "Class A print((Point &refP) " << endl;
		refP.shwXY();
	} // 이렇게 만드는건 캡슐화에 위배된다. // 부득이한 경우가 아니라면 관련 메소드는 하나의 클래스에서 관리하자!!
};
int main()
{
	int x, y;
	cout << "좌표x,y ? ";
	cin >> x >> y; //10, 30

	Point p1;
	if (p1.setX(x) && p1.setY(y))
	{
		cout << "입력된 자표를 사용하여 image 작업시작." << endl;
		//p1.shwXY();
		cout << "x : " << p1.getX() << ", y : " << p1.getY() << endl;
	}
	else
	{
		cout << "좌표가 바르지 않습니다." << endl;
		p1.shwXY();
	}
	A tmp;
	tmp.print(p1);
	

	return 0;
}