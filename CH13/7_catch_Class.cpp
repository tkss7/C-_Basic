#include <iostream>
#include <cstring>
using namespace std;

const char* account="1001";  //계좌번호
int passwd=1234;			 //비밀번호
int balance=1000;			 //잔액.

class AccountExpt  //예외클래스, 생성된 객체는 예외객체 
{ 
	char acc[10];
	int pass;
public:
	AccountExpt(char* str, int pid)  //생성자
	{
		strcpy(acc, str);
		pass=pid;
	}
	void What()
	{
		cout<<"계좌번호: "<<acc<<endl;
		cout<<"비밀번호: "<<pass<<endl;
	}
};

int main()
{
	char acc[10];
	int pid;
	int money;

	try
	{
		cout<<"계좌번호 입력: ";
		cin>>acc;	//1002 , 
		cout<<"비밀번호 4자리 입력: ";
		cin>>pid;	//1234
		
		if(strcmp(account, acc) || passwd!=pid)
			throw AccountExpt(acc, pid);
		  //개체가 생성되면서 생성자 호출하고, 해당 catch를 실행
	
		cout<<"출금액 입력: ";
		cin>>money;
		if(balance<money)
			throw money;
		
		balance-=money;
		cout<<"잔액: "<<balance<<endl;
	}
	catch(int money)
	{
		cout<<"부족 금액: "<<money-balance<<endl;
	}	
	catch(AccountExpt& expt)
	{
		cout<<"다음 입력을 다시 한번 확인 하세요"<<endl;
		expt.What();
	}
    
	cout<<"End."<<endl;

	return 0;
}
