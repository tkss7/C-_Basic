//153P_08.cpp
// 생성자를 Integer():Integer(0) {} 로 해두면 메인에서 호출할 때 Integer n; 으로 해야함
#include<iostream>
#include<string>
using namespace std;

class Integer {
private:
	int num = 0;
public:
	Integer():Integer(0) {}

	Integer(int n){num = n;}

	Integer(string s){num = stoi(s);}

	int get(){return num;}

	int set(int n)
	{
		num = n;
		return num;
	}
	int isEven()
	{
		if (num % 2 == 0)
			return 1;
		else
			return 0;
	}
};


int main()
{
	Integer n(30);
	cout << n.get() << ' ';// 30출력
	n.set(50);
	cout << n.get() << ' ';// 50출력

	Integer m("300");
	cout << m.get() << ' ';// 300출력
	cout << n.isEven(); // true(정수 1로) 출력

	return 0;
}