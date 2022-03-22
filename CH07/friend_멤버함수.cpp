//friend_멤버함수.cpp
#include<iostream>
using namespace std;
class BBB; //전방선언 : AAA 클래스가 BBB 클래스를 사용함으로 선언하여야 한다.

class AAA
{
public:
	void setData(BBB& ref, int value);
	
	void getData(BBB& ref);
	

};

class BBB
{
private:
	int data = 0;
public:
	void showData()
	{
		cout << "showData() : " << data << endl;
	}
	friend void AAA::setData(BBB& ref, int value);
	friend void AAA::getData(BBB& ref);
	//friend class AAA;

};
//BBB 클래스(friend 선언된 클래스) 이하에 선언되어야 AAA클래스의 메서드에서 BBB 자료형을 해석한다.
void AAA::setData(BBB& ref, int value)
{
	ref.data = value;
}
void AAA::getData(BBB& ref)
{
	cout << "ref.data : " << ref.data << endl;
}
int main()
{
	AAA a1;
	BBB b1;

	a1.setData(b1, 100);
	b1.showData();
	a1.getData(b1);

	return 0;
}