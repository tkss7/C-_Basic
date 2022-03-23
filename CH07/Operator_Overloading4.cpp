#include <iostream>
using namespace std;

//단항연산자 오버로딩( -(부호변경), ~(두 멤버 교환)
/*
[9, -7]
[-9, 7]

[7, -9]
*/

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	
	Point operator-()
	{
		Point temp(-xpos, -ypos);
		return temp;
	}
	
	Point& operator~()
	{
		int temp;
		temp = xpos;
		xpos = ypos;
		ypos = temp;
		return *this;
	}



};

int main()
{
	Point pos1(9, -7);

	Point pos2 = -pos1;  //pos1.operator-()
	pos1.ShowPosition();
	pos2.ShowPosition();
	cout << endl;

	~pos2; //두 값 교환
	pos2.ShowPosition(); //pos2.operator~()
	//(~pos2).ShowPosition();

	return 0;
}
