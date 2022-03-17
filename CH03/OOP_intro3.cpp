//OOP_intro3.cpp  03/17
#include<iostream>
using namespace std;
/*
	C++ ����ü : ���õ� �Լ����� �ϳ��� �η��� ������ �־� �ڷ����� �����.
*/
class Account
{
public:
	char accID[10]; //�������
	char passWd[10];
	char name[20];
	int balance;

	void Deposit(int money)  //��� �޼���
	{
		balance += money;
	}
	void Withdraw(Account& ref, int money)
	{
		if (ref.balance <= money)
		{
			cout << "�ܰ� ����!!, �����ܰ� : " << ref.balance << endl;
			return;
		}
		ref.balance -= money;
	}
};


int main()
{
	//class�� , ��ü����
	Account p1 = { "1001","1234","kim",1000 };
	cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	p1.Deposit(10000);
	cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	p1.Withdraw(p1, 5000);
	cout << p1.accID << ", " << p1.passWd << ", " << p1.name << ", " << p1.balance << endl;

	//Account p2;
	//cout << p2.accID << ", " << p2.passWd << ", " << p2.name << ", " << p2.balance << endl;


	return 0;
}