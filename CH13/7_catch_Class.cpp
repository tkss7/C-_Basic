#include <iostream>
#include <cstring>
using namespace std;

const char* account="1001";  //���¹�ȣ
int passwd=1234;			 //��й�ȣ
int balance=1000;			 //�ܾ�.

class AccountExpt  //����Ŭ����, ������ ��ü�� ���ܰ�ü 
{ 
	char acc[10];
	int pass;
public:
	AccountExpt(char* str, int pid)  //������
	{
		strcpy(acc, str);
		pass=pid;
	}
	void What()
	{
		cout<<"���¹�ȣ: "<<acc<<endl;
		cout<<"��й�ȣ: "<<pass<<endl;
	}
};

int main()
{
	char acc[10];
	int pid;
	int money;

	try
	{
		cout<<"���¹�ȣ �Է�: ";
		cin>>acc;	//1002 , 
		cout<<"��й�ȣ 4�ڸ� �Է�: ";
		cin>>pid;	//1234
		
		if(strcmp(account, acc) || passwd!=pid)
			throw AccountExpt(acc, pid);
		  //��ü�� �����Ǹ鼭 ������ ȣ���ϰ�, �ش� catch�� ����
	
		cout<<"��ݾ� �Է�: ";
		cin>>money;
		if(balance<money)
			throw money;
		
		balance-=money;
		cout<<"�ܾ�: "<<balance<<endl;
	}
	catch(int money)
	{
		cout<<"���� �ݾ�: "<<money-balance<<endl;
	}	
	catch(AccountExpt& expt)
	{
		cout<<"���� �Է��� �ٽ� �ѹ� Ȯ�� �ϼ���"<<endl;
		expt.What();
	}
    
	cout<<"End."<<endl;

	return 0;
}
