//employess.c
#include <iostream>
#include <cstring>
#include<fstream>
#include<vld.h>

using namespace std;
#define EMP_SZ 30

/*
키보드로 부터 성명(names,20), 월급(salary), 회사주소(comAddr,50)을 입력받고 출력하시오.
이때 입력되는 건수는 알지 못하며, 성명이 "end" 이면 입력을 종료하고,
입력된 데이터 출력과, 월급 평균을 구하여 출력하시오.

라이브러리함수의 성공,실패여부를 알려주는 perror()함수가 있다.
*/

class Employee {
	char** names, ** comAddr;
	int* salary;
	int Cn, salTot;
public:
	Employee() :Cn(0) {
		names = new char* [EMP_SZ];
		comAddr = new char* [EMP_SZ];
		salary = new int[EMP_SZ];
		salTot = 0;
	}
	~Employee()
	{
		for (int i = 0; i < Cn; i++)
		{
			delete[] names[i];
			delete[] comAddr[i];
		}
		delete[] names;
		delete[] comAddr;
		delete[] salary;
	}
	void input()
	{
		int i;
		char _names[20];
		char _comAddr[50];


		for (i = Cn; i < EMP_SZ; i++)
		{
			names[i] = new char[20];
			comAddr[i] = new char[50];

			cout << "(성명 ? (입력죵료:end) )";
			cin.getline(_names, 20); //kim['\0], lee, han
			if (strcmp(_names, "end") == 0)
			{
				delete names[i];
				delete comAddr[i];
				break;
			}

			strcpy(names[i], _names);



			cout << "(월급 ? )";
			cin >> *(salary + i);
			cin.clear();
			cin.ignore(100, '\n');

			cout << "(회사주소 ? )";
			cin.getline(_comAddr, 50);
			strcpy(comAddr[i], _comAddr);

		}
		Cn = i;

	}

	void output()//데이터 출력
	{
		int i;

		for (i = 0; i < Cn; i++)
		{
			cout << names[i] << ", " << salary[i] << ", " << comAddr[i] << endl;
			salTot += salary[i];
		}


		if (Cn)
		{
			cout << "====================\n";
			cout << "(월급평균: " << salTot / Cn << ")" << endl;
			cout << "====================\n";

		}


	}//emp_output() end

	void find()//검색 알고리즘
	{
		int i, found;
		char s_name[20];

		while (1)
		{
			cout << "(검색할 성명 ? (검색종료:end))";
			cin >> s_name;   //lee,kim, sun ... end
			if (strcmp(s_name, "end") == 0)
				break;

			found = 1;
			for (i = 0; i < Cn; i++)
			{
				if (strcmp(names[i], s_name) == 0)
				{
					found = 0;
					cout << names[i] << ", " << salary[i] << ", " << comAddr[i] << endl;;
					//break; 
				}
			}

			if (found)
				cout << s_name << ", Not found!!! " << endl;

		} //while (1) end
	}//find() end

	int save()
	{
		const char* file = "employess.dat";
		ofstream fout(file, ios::out | ios::binary);

		if (!fout)
		{
			cout << file << " 파일열기 실패 !!!" << endl;
			return 0;
		}
		fout.write((char*)(&Cn), sizeof(Cn));
		for (int i = 0; i < Cn; i++)
		{
			fout.write(names[i], 20);
			fout.write((char*)(salary + i), sizeof(salary[0]));
			fout.write(comAddr[i], 50);
		}

		fout.close();
		cout << "저장 완료!!!!!" << endl;
		return 0;
	}//emp_save() end

	int load()
	{
		const char* file1 = "employess.dat";
		ifstream fin(file1, ios::in | ios::binary);

		if (!fin)
		{
			perror("Error : ");
			cout << "file load error. " << endl;
			return -1;
		}

		fin.read((char*)(&Cn), sizeof(Cn));

		for (int i = 0; i < Cn; i++)
		{
			names[i] = new char[20];
			comAddr[i] = new char[50];
			fin.read(names[i], 20);
			fin.read((char*)(salary + i), sizeof(salary[0]));
			fin.read(comAddr[i], 50);
		}
		fin.close();
		cout << "emps.dat load." << endl;
		return 0;
	}//emp_load() end


};


int main()
{
	int choice, stop = 1;
	Employee emp;
	emp.load();//사원정보 메모리 적재

	while(stop)
	{
		do {

			cout << "1. 사원정보 입력 " << endl;;
			cout << "2. 사원정보 출력 " << endl;;
			cout << "3. 사원정보 검색 " << endl;;
			cout << "4. 사원정보 저장 " << endl;;
			cout << "5. 사원정보 종료 " << endl;;
			cout << "Select ? (1~5) ";
			cin >> choice;
			cin.clear();
			cin.ignore(256, '\n');
		} while (cin.fail());

		switch (choice) //해당되는 번호가 없으면 다시 부름
		{
		case 1: emp.input();
			break;
		case 2: emp.output();
			break;
		case 3: emp.find();
			break;
		case 4: emp.save();
			break;
		case 5:stop = 0;
			break;
		}
		//while (getchar() != '\n');
	}//while(1)




	return 0;
}// main() end