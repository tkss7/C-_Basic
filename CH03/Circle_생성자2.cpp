//Circle_생성자2.cpp 03/17
#include<iostream>
using namespace std;
class Circle {
private:
	int radius;
public:
	Circle() :Circle(5) //이웃 생성자 호출 : 생성자 중 인자를 사용할 오버로딩된 메서드를 호출하고 돌아온다. -> 이웃 생성자 먼저 호출 후 자기 것 호출
	{
		cout << "Circle()" << endl;
	}
	Circle(int r) : radius(r) //콜론 초기화 radius(r) == radius = r; // radius(r)이 속도가 좀 더 빠르다
		//콜론초기화는 생성자만 사용 가능 , 이웃 생성자를 호출하는게 아니라 값을 넣는것임.
	{
		cout << "Circle(int r)" << endl;
		//radius = r;
	}
	int getRadius()
	{
		return radius;
	}
};
int main()
{
	Circle donut; //객체는 생성과 동시에 생성자 호출
	cout << "반지름 : " << donut.getRadius() << endl;

	Circle pizza(30);
	cout << "반지름 : " << pizza.getRadius() << endl;

	return 0;
}