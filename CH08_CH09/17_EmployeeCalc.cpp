//17_EmployeeCalc.cpp 03/24
#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(const char * name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout<<"name: "<<name;
	}

	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
	
};
//������ Ŭ����
class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)
	{  }
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout<<" PermanentWorker  ->";
		ShowYourName();
		cout<<", salary: "<<GetPay()<<endl<<endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;      //�� �ǸŽ���
	double bonusRatio;    //�󿩱� ���� 
public:
	SalesWorker(const char * name, int money, double ratio, int val)
		: PermanentWorker(name, money), salesResult(val), bonusRatio(ratio)
	{  }

	int GetPay() const
	{
		return PermanentWorker::GetPay()  
					+ (int)(salesResult*bonusRatio);
	}

	void ShowSalaryInfo() const
	{
		cout<<" SalesWorker  ->";
		ShowYourName();
		cout<<" , salary: "<<PermanentWorker::GetPay()<<" ,�ǸŻ󿩱�: "<< (int)(salesResult*bonusRatio)<< ", �հ� : " <<GetPay()<<endl<<endl;
	}
};

class EmployeeHandler // �Ϲ������� �� ��ü�� �ּҸ� ������ �ڵ鷯 Ŭ������ ���� �δ� ��찡 ����.
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) 
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++]=emp;
	}
	void ShowAllSalaryInfo() const
	{
		 
		for(int i=0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
		 
	}
	void ShowTotalSalary() const
	{
		int sum=0;
		 
		for(int i=0; i<empNum; i++)
			sum += empList[i]->GetPay();

		cout<<"=============================="<<endl;
		cout<<"Salary Sum : "<<sum<<endl;
		cout<<"=============================="<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

int main()
{
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	// ������  ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// ������ ���                                         //��������
	handler.AddEmployee(new SalesWorker("Hong", 1000, 0.1, 7000));
	handler.AddEmployee(new SalesWorker("Moon", 2000, 0.1, 5000));

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();	

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();

	return 0;
}