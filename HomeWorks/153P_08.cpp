//153P_08.cpp
// �����ڸ� Integer():Integer(0) {} �� �صθ� ���ο��� ȣ���� �� Integer n; ���� �ؾ���
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
	cout << n.get() << ' ';// 30���
	n.set(50);
	cout << n.get() << ' ';// 50���

	Integer m("300");
	cout << m.get() << ' ';// 300���
	cout << n.isEven(); // true(���� 1��) ���

	return 0;
}