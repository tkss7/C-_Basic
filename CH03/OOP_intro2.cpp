//OOP_intro2.cpp  03/17
#include<iostream>
using namespace std;
/*
	C++ 구조체 : 관련된 함수들을 하나의 부류로 인정해 주어 자료형을 만든다. 
*/
struct Account
{
	char accID[10];
	char passWd[10];
	char name[20];
	int balance;
	void Deposit(int money)
	{
		balance += money;
	}
	void Withdraw(Account& ref, int money)
	{
		if (ref.balance <= money)
		{
			cout << "잔고 부족!!, 현재잔고 : " << ref.balance << endl;
			return;
		}
		ref.balance -= money;
	}
};


int main()
{
	Account p1 = { "1001","1234","kim",1000 };
	cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	p1.Deposit(10000);
	cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	p1.Withdraw(p1, 5000);
	//cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	return 0;
}