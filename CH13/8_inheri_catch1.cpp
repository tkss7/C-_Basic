#include <iostream>
using namespace std;

class ExceptA
{
public:
	void What()
	{
		cout<<"ExceptA ����"<<endl;
	}
};

class ExceptB : public ExceptA
{
public:
	void What()
	{
		cout<<"ExceptB ����"<<endl;
	}
};

class ExceptC : public ExceptB
{
public:
	void What()
	{
		cout<<"ExceptC ����"<<endl;
	}
};

void ExcepFunction(int ex)
{
	//���� Ŭ������ ��Ӱ��踦 �����Ѵ�.ExceptC ����, ExceptB ���ܴ� ���ÿ� ExceptA ���ܵ� �ȴ�.
	if(ex==1)
		throw ExceptA(); //��ü����
	else if(ex==2)
		throw ExceptB();
	else if(ex==3)
		throw ExceptC();
	else
		throw "error";
}

int main()
{

	int exID;
	cout<<"�߻���ų ������ ����: ";
	cin>>exID;

	try{
		ExcepFunction(exID);
	}


	catch (ExceptC& ex) //�Ļ�Ŭ�������� ���ܹ��� �ָ� �ȴ�.
	{
		cout << "catch(ExceptC& ex)�� ���� ó��" << endl;
		ex.What();
	}
	catch(ExceptB& ex)
	{
		cout<<"catch(ExceptB& ex)�� ���� ó��"<<endl;
		ex.What();
	}
		catch(ExceptA& ex)  //�Ļ�Ŭ���� ���Ŭ������ ��������(Up Casting)
	{
		cout<<"catch(ExceptA& ex)�� ���� ó��"<<endl;
		ex.What();
	}	
	catch(const char *)
	{
		cout<<"�˼� ���� ���ܹ߻�."<<endl;
	}

	cout << "End. " << endl;

	return 0;
}