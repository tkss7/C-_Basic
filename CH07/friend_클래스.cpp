//friend_클래스.cpp
#include<iostream>
using namespace std;

class AAA
{
private:
	int data;
public:
	void showData()
	{
		cout << "showData() data: "<< data << endl;
	}
	friend class BBB; //BBB 클래스에서 AAA 멤버 접근을 허용
};

class BBB
{
public:
	void setData(AAA &ref, int n)
	{
		ref.data = n;
	}
};

int main()
{
	AAA a1;
	BBB b1;

	b1.setData(a1, 100);
	a1.showData();

	return 0;
}