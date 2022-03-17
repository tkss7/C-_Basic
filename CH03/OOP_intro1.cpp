//OOP_intro1.cpp  03/17
#include<iostream>
using namespace std;
/*
	구조체 문제 : 구조체는 관련된 데이터를 담을 수 있다. 그러나 데이터를 조작하여 결과를 원하는 함수를 따로 구현해야 한다.
*/
struct Account
{
	char accID[10];
	char passWd[10];
	char name[20];
	int balance;
};

void Deposit(Account &ref, int money)
{
	ref.balance += money;
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
int main()
{
	Account p1 = { "1001","1234","kim",1000 };
	cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	Deposit(p1,10000);
	cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	Withdraw(p1,57000);
	cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	return 0;
}