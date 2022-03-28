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
    Point(const Point& ref)  //���������        //Ŭ���� ����� �����Ҵ��� �ް� �ִ°� �ִٸ� �������Ұ� : ���������, ������
    {
        cout << "Point(const Point& ref)" << endl;
        a = ref.a;
        b = ref.b;
    }

    void showData()
    {
        cout << "a : " << a << ", b :  " << b << endl;
    }
    Point operator+(const Point& ref) //Ŭ���� ����� �����Ҵ��� �ް� �ִ°� �ִٸ� �������Ұ� : ���������, ������
    {
        cout << "Point operator+(const Point& ref)" << endl;
        return Point(a + ref.a, a + ref.a);
    }
    void operator=(const Point& ref) //Ŭ���� ����� �����Ҵ��� �ް� �ִ°� �ִٸ� �������Ұ� : ���������, ������
    {
        cout << "operator=(const Point& ref2)" << endl;
        a = ref.a;
        b = ref.b;
    }
};

template<typename T>
T Add(T _a, T _b)
{
    return _a + _b;              //��ü���� ������ �Ұ� -> ������ �����ε� data.operator+(data2)
}

int main()
{
    Point<int>p1(1, 1);
    Point<int>p2(2, 2);

    Point<int>p3 = Add(p1, p2);     //��������� ȣ�� Ÿ�̹� : ��ü�� ����� ���ÿ� ��ü�� �ʱ�ȭ
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