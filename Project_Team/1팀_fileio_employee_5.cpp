#include "vld.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#define EMP_SZ 30

class Employee
{
private:
	char* names;
	char* comAddr;
	int salary;
public:
	void showInfo()
	{
		cout << names << ", " << comAddr << ", " << salary << endl;
	}
	void setInfo(const char* _names, const char* _addr, int _salary)
	{
		names = new char[strlen(_names) + 1];
		strcpy(names, _names);
		comAddr = new char[strlen(_addr) + 1];
		strcpy(comAddr, _addr);
		salary = _salary;
	}
	char* getNames()
	{
		return names;
	}
	char* getAddr()
	{
		return comAddr;
	}
	int getSalary()
	{
		return salary;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[EMP_SZ];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++) {
			delete empList[i]->getNames();
			delete empList[i]->getAddr();
			delete empList[i];
		}
	}
	void Input_Emp();
	void Output_Emp();
	void Find_Emp();
	int Save_Emp();
	void Load_Emp();
};

void EmployeeHandler::Input_Emp()
{
	char names[20];
	char comAddr[50];
	int salary;
	int i;
	for (i = empNum; i < EMP_SZ; i++) {
		cout << "���� ? (end�Է½� ����) ";

		cin >> names;
		if (strcmp(names, "end") == 0) {
			break;
		}
		cout << "�ּ� ? ";
		cin >> comAddr;
		cout << "���� ? ";
		cin >> salary;

		empList[i] = new Employee;
		(*(empList[i])).setInfo(names, comAddr, salary);
	}
	empNum = i;
}

void EmployeeHandler::Output_Emp()
{
	for (int i = 0; i < empNum; i++) {
		(*(empList[i])).showInfo();
	}
}

void EmployeeHandler::Find_Emp()
{
	char s_name[20];
	int found;
	while (1)
	{
		cout << "\n�˻��� ���� ? (�˻����� : end) ";
		cin >> s_name;				//kim,lee,sun, ..., end
		if (strcmp(s_name, "end") == 0)
			break;

		found = 1;
		for (int i = 0; i < empNum; i++) {
			if (strcmp(s_name, (*(empList[i])).getNames()) == 0)  // � ������ 
			{ 
				found = 0;
				(*(empList[i])).showInfo();
				//break;
			}
		}
		if (found) {
			cout << s_name << ", Not found!!!";
		}
	}	//while(1) end
}


int EmployeeHandler::Save_Emp()
{
	char* _names;
	char* _addr;
	int _salary;
	ofstream fout("emp.dat", ios::binary);
	if (!fout)
	{
		cout << "emp.dat ���Ͽ��� ���� !!!" << endl;
		return -1;
	}
	fout.write((char*)&empNum, sizeof(int));
	cout << empNum << "���� ����� �����߽��ϴ�." << endl;
	for (int i = 0; i < empNum; i++) {
		_names = (*empList[i]).getNames();
		fout.write((char*)_names, 20);
		_addr = (*empList[i]).getAddr();
		fout.write((char*)_addr, 50);
		_salary = (*empList[i]).getSalary();
		fout.write((char*)&_salary, 4);
	}

	fout.close();

	cout << "emps.dat ����" << endl;
}	//emp_save() end

void EmployeeHandler::Load_Emp()
{
	char names[20];//����� �� �ٸ���
	char comAddr[50];
	int salary;
	ifstream fin("emp.dat", ios::binary);
	if (!fin)
	{
		cout << "emp.dat ���Ͼ���" << endl;
		return;
	}

	fin.read((char*)&empNum, sizeof(int));
	cout << empNum << "���� ����� �ҷ��Խ��ϴ�." << endl;
	for (int i = 0; i < empNum; i++) {
		fin.read((char*)names, sizeof(names));
		fin.read((char*)comAddr, sizeof(comAddr));
		fin.read((char*)&salary, sizeof(int));

		empList[i] = new Employee;
		(*(empList[i])).setInfo(names, comAddr, salary);
	}
	fin.close();

	cout << "emps.dat �ε�" << endl;
}	//emd_load() end


int main()
{
	//1.����
	int choice, stop = 1;

	EmployeeHandler handler;

	handler.Load_Emp();		//������� �޸� ���� - �����Ҷ� ���Ͽ��� �ҷ���

	while (stop)
	{
		cout << "\n 1. ������� �Է�" << endl;
		cout << "2. ������� ���" << endl;
		cout << "3. ������� �˻�" << endl;
		cout << "4. ������� ����" << endl;
		cout << "5. ������� ����" << endl;
		cout << "Select ? (1~5) ";
		cin >> choice;

		switch (choice)
		{
		case 1: handler.Input_Emp();
			break;
		case 2: handler.Output_Emp();
			break;
		case 3: handler.Find_Emp();
			break;
		case 4: handler.Save_Emp();
			break;
		case 5: stop = 0;
			break;
		}

		while (getchar() != '\n');	//a�� �� ���ѹݺ��ϴ°��� ���� : ���� ���������� ����(\n)�� �������Ƿ� �׶����� getchar()�ݺ�
	}	//while(1) end

	cout << "End." << endl;

	return 0;
}