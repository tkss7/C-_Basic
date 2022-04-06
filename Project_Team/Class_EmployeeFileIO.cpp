//Class_EmployeeFileIO.c

#include "vld.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#define EMP_SZ 50

#define NAME_SZ 20
#define COMADDR_SZ 50

class EMPLOYEE
{
private:
	char name[NAME_SZ];
	int salary;
	char comAddr[COMADDR_SZ];
public:
	EMPLOYEE()
	{
		strcpy(name, "");
		strcpy(comAddr, "");
		salary = 0;
	}

	~EMPLOYEE() {	}

	EMPLOYEE* input()
	{
		int i;
		EMPLOYEE* ptr;

		ptr = new EMPLOYEE;

		cout << "\n성명 ? (입력종료:end) ";
		cin.getline(ptr->name, NAME_SZ);

		if (strcmp(ptr->name, "end") == 0)   //종료조건
		{ 
			delete ptr;
			return nullptr;
		}

		cout << "월급 ? ";
		cin >> ptr->salary;
		cin.ignore(1);

		cout << "회사주소 ? ";
		cin.getline(ptr->comAddr, COMADDR_SZ);

		return ptr;
	}

	int getSalry() const
	{
		getData();
		return salary;
	}

	void getData() const
	{
		cout << name << ", " << salary << ", " << comAddr << endl;;
	}

	char* getName()
	{
		return name;
	}
};

//int EMPLOYEE::Count = 0;

class EMPHandler : public EMPLOYEE
{
private:
	EMPLOYEE* empPtr[EMP_SZ];
	int Count;
public:
	EMPHandler() : Count(0)
	{
		//cout << " sizeof( empPtr[EMP_SZ]) : " << sizeof(empPtr) << endl;
	}

	~EMPHandler()
	{
		for (int i = 0; i < Count; i++)
			delete empPtr[i];
	}

	void AddEmployee()
	{
		int i;
		for (i = Count; i < EMP_SZ; i++)
		{
			empPtr[i] = input();
			if (empPtr[i] == nullptr)
				break;
		}

		Count = i;
	}

	void outputEmployee() const
	{
		int sum = 0;

		cout << endl;
		for (int i = 0; i < Count; i++)
			sum += empPtr[i]->getSalry();

		cout << "==============================" << endl;
		cout << "Salary avg : " << sum / Count << endl;
		cout << "==============================" << endl;

	}

	void findEmployee()
	{
		int i, found;
		char s_name[20], *getname;

		while (1)
		{
			cout << "\n검색할 성명 ? (검색종료:end) ";
			cin.getline(s_name, 20);   //lee, kim, sun, ... end
			if (strcmp(s_name, "end") == 0)
				break;

			found = 1;

			for (i = 0; i < Count; i++)
			{

				getname = empPtr[i]->getName();
				if (strcmp(getname, s_name) == 0)
				{
					found = 0;
					empPtr[i]->getData();
				}
			}

			if (found)
				cout << s_name << ", Not found !!! " <<  endl;

		}//while (1) end
	}

	void saveEmployee()
	{
		const char* file = "emps.dat";

		ofstream fout;
		fout.open(file, ios::out | ios::binary); // 읽기모드

		if (!fout)
		{
			cout << "emp_save() 파일 열기 오류";
			return;
		}

		fout.write((char*)&Count, sizeof(Count));
		for (int i = 0; i < Count; i++)
			fout.write((char*)(empPtr[i]), sizeof(EMPLOYEE) );

		fout.close();

		printf("ems.dat Save !!! \n");
	}

	void loadEmployee()
	{
		const char* file = "emps.dat";
		EMPLOYEE* ptr;

		ifstream fin;
		fin.open(file, ios::in | ios::binary); // 읽기모드

		if (!fin)
		{
			cout << "emp_load() 파일 열기 오류";
			return;
		}

		fin.read((char*)&Count, sizeof(Count));  

		for (int i = 0; i < Count; i++)
		{
			empPtr[i] = new EMPLOYEE;   
			fin.read((char*)(empPtr[i]), sizeof(EMPLOYEE)); 
		}
		fin.close();

		printf("ems.dat Load!!! \n");
	}
};


int main()
{
	int choice, stop = 1;

	EMPHandler emps;

	emps.loadEmployee();

	while (stop)
	{
		cout << "\n1. 사원정보 입력 \n";
		cout << "2. 사원정보 출력 \n";
		cout << "3. 사원정보 검색 \n";
		cout << "4. 사원정보 저장 \n";
		cout << "5. 프로그램 종료 \n";
		cout << "Select ? (1~5) ";
		cin >> choice;  //1, 2, 3, 7, 1, 4
		cin.ignore(1);

		switch (choice)
		{
		case 1:  emps.AddEmployee();
			break;
		case 2: emps.outputEmployee();
			break;
		case 3: emps.findEmployee();
			break;
		case 4: emps.saveEmployee();
			break;
		case 5: stop = 0;
			break;
		}

	} //while(stop) end

	printf("End. \n");

	return 0;
} //main() end
