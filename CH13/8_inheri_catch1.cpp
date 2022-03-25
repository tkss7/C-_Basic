#include <iostream>
using namespace std;

class ExceptA
{
public:
	void What()
	{
		cout<<"ExceptA 예외"<<endl;
	}
};

class ExceptB : public ExceptA
{
public:
	void What()
	{
		cout<<"ExceptB 예외"<<endl;
	}
};

class ExceptC : public ExceptB
{
public:
	void What()
	{
		cout<<"ExceptC 예외"<<endl;
	}
};

void ExcepFunction(int ex)
{
	//예외 클래스가 상속관계를 구성한다.ExceptC 예외, ExceptB 예외는 동시에 ExceptA 예외도 된다.
	if(ex==1)
		throw ExceptA(); //객체생성
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
	cout<<"발생시킬 예외의 숫자: ";
	cin>>exID;

	try{
		ExcepFunction(exID);
	}


	catch (ExceptC& ex) //파생클래스부터 예외문을 주면 된다.
	{
		cout << "catch(ExceptC& ex)에 의한 처리" << endl;
		ex.What();
	}
	catch(ExceptB& ex)
	{
		cout<<"catch(ExceptB& ex)에 의한 처리"<<endl;
		ex.What();
	}
		catch(ExceptA& ex)  //파생클래스 기반클래스로 참조전달(Up Casting)
	{
		cout<<"catch(ExceptA& ex)에 의한 처리"<<endl;
		ex.What();
	}	
	catch(const char *)
	{
		cout<<"알수 없는 예외발생."<<endl;
	}

	cout << "End. " << endl;

	return 0;
}