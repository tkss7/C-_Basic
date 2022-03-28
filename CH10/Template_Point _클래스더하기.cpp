//Template_Point _클래스더하기.cpp
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
	void operator=(const Point& ref) //클래스 멤버중 동적할당을 받고 있는게 있다면 만들어야할것 : 복사생성자, 연산자
	{
		cout << "Point operator=(const Point& ref)" << endl;
		x = ref.x;
		y = ref.y;

		
	}

};



template <typename T>
T Add(T ref1, T ref2) // 이러면 객체 반환시 복사생성자 불려짐 , 만약 &ref로 하면 안불려지던데?
{
	T temp; // 생성자
	temp = ref1 + ref2; // + 연산자 -> 대입 연산자
	return temp; //객체가 파라메터로 넘어가면 복사생성자가 불려진다. // 복사 생성자
}

//template <typename T>
//T Add(T ref1, T ref2) // 이러면 객체 반환시 복사생성자 불려짐 , 만약 &ref로 하면 안불려지던데?
//{
//	return  ref1 + ref2; + 연산자
//}


int main()
{
	Point<int> p1(1, 1);
	Point<int> p2(2, 2);
	
	Point<int>p3 = Add(p1, p2); // 복사생성자 2번 , Add에서 +연산자 한번
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