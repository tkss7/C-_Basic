//friend_클래스_전역함수.cpp
#include<iostream>
using namespace std;

class Counter
{
private:
	int value;
public:
	Counter() :value(0)
	{

	}
	void showData()
	{
		cout << "value : " << value << endl;
	}

	friend void setValue(Counter& ref, int n); //외부접근 허락
};
//전역함수에서 객체 private 멤버 접근 (클래스에서 friend 선언)
void setValue(Counter& ref, int n) //전역함수에서 객체 private 멤버 접근 (클래스에서 friend 선언)
{
	ref.value = n; //외부접근이라 안됨

}
int main()
{
	Counter cnt;

	cnt.showData();

	setValue(cnt, 5000);
	cnt.showData();


	return 0;
}