//11-Circle_소멸자실행순서.cpp 03/18
#include <iostream> 
using namespace std; 

//생성소멸은 생성 반대로 실행

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
	cout << "반지름 " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "Circle(int r) : " << radius <<  endl;
}

Circle::~Circle() { // 소멸자, 개체 소멸 전 실행(자원반납) 사용자정의 소멸자가 없으면 빈괄호가 자동 생성된다.
	cout << "~Circle() :" << radius << " 소멸" << endl;
}

double Circle::getArea()  //멤버메서드
{
	return 3.14*radius*radius;
}

//전역 객체변수 데이터 세그먼트에 할당 -> 제일 먼저
Circle globalDonut(1000);    //1
Circle globalPizza(2000);    //2

void f() //전역함수
{
	Circle fDonut(100);    //5
	Circle fPizza(200);    //6
}

int main()
{
	Circle mainDonut;       //3
	Circle mainPizza(30);   //4

	f();
	// 소멸은 할당받은 역순으로 소멸된다. 

	return 0;
}
