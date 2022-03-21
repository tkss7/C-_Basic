#include<iostream> //03/18
using namespace std;
// C++ 구조체와 Class의 차이점은 오로지 디폴트 값이 구조체는 Public , Class는 Private 라는 점 뿐이다~
class Circle
{
private:
	int radius=1;
public:
	Circle(){ cout << "Circle()" << radius << endl; }
	Circle(int r)
	{

		radius = r;
		cout << "Circle(int r)" << radius << endl;
	}
	~Circle()
	{
		cout << "~Circle()"<<radius<<endl;
	}
	int getRadius()
	{
		return radius;
	}
	double getArea()
	{
		return radius * radius * 3.15;
	}
};

int main()
{
	Circle donut;

	Circle pizza(30);

	Circle* p = &donut; //객체변수
	cout << "p->getArea()" << p->getArea() << endl;

	p=&pizza;
	cout << "p->getArea()" << p->getArea() << endl;

	return 0;
}