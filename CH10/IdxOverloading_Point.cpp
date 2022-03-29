//IdxOverloading_Point.cpp
#include <iostream>
using namespace std;

//Point Ŭ���� ��ü�� �迭�� �����Ͽ�, ��ü�� �迭ó�� ���, ���� �����ڷ� �迭 ���
/***************** Point Class **************************/
class Point {
private:
	int x, y;
public:
	Point(int _x=0, int _y=0):x(_x), y(_y){}
	friend ostream& operator<<(ostream& os, const Point& p);
	void operator=(const Point &p); //���Կ�����
};

ostream& operator<<(ostream& os, const Point& p)
{
	os<<"["<<p.x<<", "<<p.y<<"]";	
	return os;
}
 //��ü = ��ü => ��ȣ�����ڰ� �ʿ���

void Point::operator=(const Point &p) // ����Ʈ �޼ҵ�?
{
	cout<<"operator=(Point &p) called. "<<endl;
	this->x=p.x;
	this->y=p.y;
}


/***************** PointArr Class **************************/
const int SIZE=5;  // ������� ũ��.

class PointArr 
{
private:
	Point nArr[SIZE];
	int idx;
public:
	PointArr():idx(0){}
	int GetIdx()
	{
		return idx;
	}

	Point& operator[](int i); // �迭 ��ҿ� ����.
};

Point& PointArr::operator[](int i)
{
	if(i<0 || i>=SIZE)
	{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
	}

	idx = i;
	return nArr[i];
}

int main()
{
	PointArr arr; 
	int i;

	//// ���� ��� ���� �� ����
	arr[0]=Point(10, 10); 
	arr[1]=Point(20, 20); 

	arr[2]=Point(30, 30); 
	arr[3]=Point(40, 40);  

	int idx = arr.GetIdx();
	for(i=0;i<=idx;i++)
	   cout<<arr[i]<<endl;  //���� ������ �����޼���

	return 0;
}
