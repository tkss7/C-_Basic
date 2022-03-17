//New_구조체동적할당.cpp 03/17 O
#include<iostream>
using namespace std;

typedef struct _Point
{
	int x;
	int y;

}Point;
void Pnt1(Point &ref)
{
	ref.x = 100;
	ref.y = 100;
}
void Pnt2(Point *p)
{
	p->x = 200;
	p->y = 200;
}
Point *PntAdder(Point &ref1, Point &ref2)
{
	Point* p3 = new Point;
	p3->x = ref1.x + ref2.x;
	p3->y = ref1.y + ref2.y;

	return p3;
}
Point &PntAdder2(Point& ref1, Point& ref2)
{
	Point* p3 = new Point;
	p3->x = ref1.x + ref2.x;
	p3->y = ref1.y + ref2.y;

	return *p3;
}
int main()
{
	Point* p1 = new Point;

	p1->x = 10;
	p1->y = 10;

	Point* p2 = new Point;
	p2->x = 20;
	p2->y = 20;

	Pnt1(*p1);
	cout << "p1: " << p1->x << ", " << p1->y << endl;

	Pnt2(p2);
	cout << "p2: " << p2->x << ", " << p2->y << endl;

	Point *p3 = PntAdder(*p1, *p2);
	cout << "p3: " << p3->x << ", " << p3->y << endl;

	Point &p4 = PntAdder2(*p1, *p2);
	cout << "p4: " << p4.x << ", " << p4.y << endl;

	delete p1;
	delete p2;
	delete p3;
	delete &p4;//참조자는 참조변수로 지운다.
	p1 = p2 = p3 = NULL;
	return 0;
}