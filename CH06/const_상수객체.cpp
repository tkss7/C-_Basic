//const_상수객체.cpp
#include<iostream>
using namespace std;

class AAA
{
private:
	mutable int num; //원래 상수화된 멤버는 수정 안하는게 맞지만 여기선 방법이 있다만 알려준 것

public:
	AAA(int n) : num(n)
	{

	}

	void showData()
	{
		cout << "void showData()" << endl;
		cout << "num : " << num << endl;
	}
	void showData() const // 오버로딩
	{
		cout << "void showData() const" << endl;
		cout << "num : " << num << endl;
	}

	void Add(int n) const
	{
		num += n;
	}
};

int main()
{
	AAA a1(200); //일반객체 : 주로씀
	a1.showData(); // 일반메서드와 상수화된 메서드가 둘 다있을 땐 우선순위는 일반메서드임, 만약 일반메서드가 없다면 그땐 상수화된 메서드를 출력함.

	const AAA a2(100); //상수객체 : 일반 메서드 접근이 불가함
	a2.showData(); // 상수메서드만 사용할 수 있다.

	a1.Add(50);
	a1.showData();

	a2.Add(50);
	a2.showData();

	return 0;
}