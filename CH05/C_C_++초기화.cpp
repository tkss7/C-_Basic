//C_C_++초기화.cpp
#include<iostream>
using namespace std;

class AAA
{
private:
	int value;
public:
	
	explicit AAA(int n) // 명시적 호출만 허용한다.
	{
		value = n;
	}

	void showData()
	{
		cout << "val : " << value << endl;
	}
	
};
int main()
{
	int n1 = 20; //C style 초기화
	int n2(30); //C++ style 초기화
	cout << "n1: " << n1 << ", n2: " << n2 << endl;

	AAA a1(100); //C++ Style 초기화
	a1.showData();
	//AAA a2 = 200; // C Style 초기화, 묵시적으로 C++ Style로 변환된다.
	//a2.showData();
	return 0;
}