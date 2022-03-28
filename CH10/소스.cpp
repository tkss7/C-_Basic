//ppt 18p

#include<iostream>
using namespace std;

template<typename T>
class Point
{
private:
    T a, b;
public:
    Point(T _a = 0, T _b = 0)
    {
        a = _a;
        b = _b;
    }
    Point(const Point& ref)  //복사생성자        //클래스 멤버중 동적할당을 받고 있는게 있다면 만들어야할것 : 복사생성자, 연산자
    {
        cout << "Point(const Point& ref)" << endl;
        a = ref.a;
        b = ref.b;
    }

    void showData()
    {
        cout << "a : " << a << ", b :  " << b << endl;
    }
    Point operator+(const Point& ref) //클래스 멤버중 동적할당을 받고 있는게 있다면 만들어야할것 : 복사생성자, 연산자
    {
        cout << "Point operator+(const Point& ref)" << endl;
        return Point(a + ref.a, a + ref.a);
    }
    void operator=(const Point& ref) //클래스 멤버중 동적할당을 받고 있는게 있다면 만들어야할것 : 복사생성자, 연산자
    {
        cout << "operator=(const Point& ref2)" << endl;
        a = ref.a;
        b = ref.b;
    }
};

template<typename T>
T Add(T _a, T _b)
{
    return _a + _b;              //객체끼리 덧셈이 불가 -> 연산자 오버로딩 data.operator+(data2)
}

int main()
{
    Point<int>p1(1, 1);
    Point<int>p2(2, 2);

    Point<int>p3 = Add(p1, p2);     //복사생성자 호출 타이밍 : 객체를 선언과 동시에 객체로 초기화
    p3.showData();

    Point<double>p4(1.1, 1.1);
    Point<double>p5(2.1, 2.1);

    Point<double>p6 = Add(p4, p5);
    p6.showData();

    Point<int>p7;
    p7 = p1;                         //p7.operator=(p1);
    p7.showData();

    return 0;
}