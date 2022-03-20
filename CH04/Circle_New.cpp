//Circle_New.cpp 03/18
#include<iostream>
using namespace std;
//this-> : 디폴트 값임 ; 객체가 여러개고 메소드가 하나인데 그걸 어케구분하는 건가? == this
/*
	만약 int setRadius(int radius)
	{
		radius=radius; ==> 뭐가 뭔지구분안되니깐 this->radius=radius 로 해야한다.
	}

	class Circle  //클래스명
{
private:
	int radius; //멤버 변수
public:
	Circle() :radius(1) { cout << "Circle()" << endl; } //생성자
	~Circle()  // 소멸자
	{
		cout << "~Circle()" << radius << endl;
	}
	int getRadius() { return radius; } //메소드

	int main()
	Circle c1(5); //객체 변수 or 객체
*/
class Circle
{
private:
	int radius;
public:
	Circle() :radius(1) { cout << "Circle()" << endl; }
	Circle(int r)
	{

		this->radius = r;
		cout << "Circle(int r)" << radius << endl;
	}
	~Circle()
	{
		cout << "~Circle()" << radius << endl;
	}
	Circle(const Circle& c) // 복사 생성자로 복사하면 이걸 설정한해도 디폴트 값으로 들어간다.
	{
		this->radius = c.radius;
		cout << "Circle(const Circle &c)" <<radius <<endl;
	}
	int getRadius() { return radius; }
	int setRadius(int r)
	{
		this->radius = r;
		return radius;
	}
	double getArea() { return radius * radius * 3.15; }

};

int main()
{
	Circle c1(5); //객체 변수;
	Circle* p1 = new Circle;
	Circle* p2 = new Circle;;
	
	Circle* p3;
	p3 = new Circle(10);
	p3->setRadius(25);

	cout << p1->getRadius() << endl;
	cout << p2->getRadius() << endl;
	cout << p3->getRadius() << endl;

	Circle* p4 = &c1;
	cout << p4->getRadius() << endl;

	Circle* p5 = new Circle(c1); //복사 생성자 : c1을 복사하여 동적할당받은 Circle의 객체에 복사한다.

	cout << p5->getRadius() << endl;

	delete p1;
	delete p2; 
	delete p3;
	delete p5;


	return 0;
}
/*
	복사 생성자 : 얕은 복사와 깊은 복사로 나뉨
		얕은복사 : 포인터를 사용 할 경우 복사한 객체와 복사된 객체의 name이 동시에 같은 주소를 가리킴
		-> 한쪽의 값을 변경하면 나머지 한쪽도 변경됨,
		->나중에 동적할당 메모리 반환과정에서 같은 것을 두번 반환하므로 컴파일 오류뜸

		깊은복사 : 포인터를 사용해도 문자열만 복사하고 복사된 객체에는 동적할당된 공간에 문자열을 저장하므로
		얕은복사와 같은 오류가 생기지않는다.
		-> 문자열 길이만큼 동적할당 하여 배열만들고 객체의 멤버에 넣음 -> strcpy를 이용해 문자열복사
*/