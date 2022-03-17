//Class_Acess.cpp 03/17
#include<iostream>
using namespace std;
/*
	protected : 상속관계에서만 쓸 수 있다.
*/
class Counter
{ // 디폴트 값은 private임, 가독성을 위해서 쓰자!

private: // 내부접근을 허락 , 클래스 내의 public 메소드 안에서만 사용 가능
	int value2 = 100;
public: // 외부접근을 허락
	int value;
	void InCrement()
	{
		value++;  //내부접근
		value2++; //내부접근
	}
	int getValue()
	{
		return value2;
	}
};

int main()
{
	Counter cnt;

	cnt.value = 1;  //외부접근
	cnt.InCrement(); //외부접근 : 클래스 밖에서 접근하는 것

	cout << "cnt.value: " << cnt.value << endl; // 2 : 외부접근
	cout << "cnt.value2: " << cnt.getValue() << endl; // 2 : 외부접근

	return 0;
}