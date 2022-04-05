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
		cout << "성명 ? (end입력시 종료) ";

		cin >> names;
		if (strcmp(names, "end") == 0) {
			break;
		}
		cout << "주소 ? ";
		cin >> comAddr;
		cout << "월급 ? ";
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
		cout << "\n검색할 성명 ? (검색종료 : end) ";
		cin >> s_name;				//kim,lee,sun, ..., end
		if (strcmp(s_name, "end") == 0)
			break;

		found = 1;
		for (int i = 0; i < empNum; i++) {
			if (strcmp(s_name, (*(empList[i])).getNames()) == 0)  // 몇개 들어가는지 
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
		cout << "emp.dat 파일열기 실패 !!!" << endl;
		return -1;
	}
	fout.write((char*)&empNum, sizeof(int));
	cout << empNum << "개의 명단을 저장했습니다." << endl;
	for (int i = 0; i < empNum; i++) {
		_names = (*empList[i]).getNames();
		fout.write((char*)_names, 20);
		_addr = (*empList[i]).getAddr();
		fout.write((char*)_addr, 50);
		_salary = (*empList[i]).getSalary();
		fout.write((char*)&_salary, 4);
	}

	fout.close();

	cout << "emps.dat 저장" << endl;
}	//emp_save() end

void EmployeeHandler::Load_Emp()
{
	char names[20];//여기는 왜 다른지
	char comAddr[50];
	int salary;
	ifstream fin("emp.dat", ios::binary);
	if (!fin)
	{
		cout << "emp.dat 파일없음" << endl;
		return;
	}

	fin.read((char*)&empNum, sizeof(int));
	cout << empNum << "개의 명단을 불러왔습니다." << endl;
	for (int i = 0; i < empNum; i++) {
		fin.read((char*)names, sizeof(names));
		fin.read((char*)comAddr, sizeof(comAddr));
		fin.read((char*)&salary, sizeof(int));

		empList[i] = new Employee;
		(*(empList[i])).setInfo(names, comAddr, salary);
	}
	fin.close();

	cout << "emps.dat 로드" << endl;
}	//emd_load() end


int main()
{
	//1.선언
	int choice, stop = 1;

	EmployeeHandler handler;

	handler.Load_Emp();		//사원정보 메모리 적재 - 시작할때 파일에서 불러옴

	while (stop)
	{
		cout << "\n 1. 사원정보 입력" << endl;
		cout << "2. 사원정보 출력" << endl;
		cout << "3. 사원정보 검색" << endl;
		cout << "4. 사원정보 저장" << endl;
		cout << "5. 사원정보 종료" << endl;
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

		while (getchar() != '\n');	//a가 들어가 무한반복하는것을 방지 : 버퍼 마지막에는 엔터(\n)가 들어가있으므로 그때까지 getchar()반복
	}	//while(1) end

	cout << "End." << endl;

	return 0;
}