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
	char** names; // names[EMP_SZ][20]을 받기위한 더블 포인터
	char **comAddr; // comAddr[EMP_SZ][50]을 받기위한 더블 포인터
	int *salary;
	int Cn, salTot;

public:
	Employee() :Cn(0) {
		names = new char* [EMP_SZ]; // 30행을 먼저 배열포인터로 할당
		comAddr = new char* [EMP_SZ]; // 30행을 먼저 배열포인터로 할당
		salary = new int[EMP_SZ]; // 30열 동적 할당
		salTot = 0;
	}
	~Employee() // 할당된 메모리들 전부 해제
	{
		for (int i = 0; i <Cn; i++)
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
		char _names[20]; //입력 임시 버퍼
		char _comAddr[50]; // 입력 임시 버퍼

		
		for (i = Cn; i < EMP_SZ; i++)
		{
			names[i] = new char[20]; // 20열 동적할당( 20byte)
			comAddr[i] = new char[50]; // 50열 동적할당 ( 50byte)

			cout<< "(성명 ? (입력죵료:end) )";
			cin.getline(_names, 20); // 입력버퍼에 20바이트 입력
			if (strcmp(_names, "end") == 0)
			{
				delete names[i]; // end 입력되면 방금 할당 받은 행의 20byte 할당 해제
				delete comAddr[i]; // end 입력되면 방금 할당 받은 행의 50byte 할당 해제
				break;
			}

			strcpy(names[i], _names); // 버퍼 -> 배열로 복사
			


			cout<<"(월급 ? )";
			cin >> *(salary+i);
			cin.clear();
			cin.ignore(100, '\n');

			cout<<"(회사주소 ? )";
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
			cout<<"====================\n";
			cout << "(월급평균: " << salTot / Cn<<")" << endl;
			cout<<"====================\n";

		}

		// 클래스 포인터는 (*x).xx 형식으로 해야하는듯?

	}//emp_output() end
	// cin.ignore(1) // 엔터값 버림
	void find()//검색 알고리즘
	{
		int i,found;
		char s_name[20];

		while (1)
		{
			cout<<"(검색할 성명 ? (검색종료:end))";
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

		fout.write((char*)(&Cn), sizeof(Cn)); // Cn주소에 4바이트만큼 꺼내 저장
		for (int i = 0; i < Cn; i++)
		{
			fout.write(names[i],20); // i 번째열의 20byte를 파일에 저장
			fout.write((char*)(salary + i), sizeof(salary[0]));
			fout.write(comAddr[i], 50);
		}

		fout.close();
		cout << "저장 완료!!!!!" << endl;
		return 0;
	}//emp_save() end

	int load()
	{
		const char* file1= "employess.dat";
		ifstream fin(file1, ios::in | ios::binary);

		if (!fin)
		{
			perror("Error : ");
			cout << "file load error. " << endl;
			return -1;
		}

		fin.read((char*)(&Cn), sizeof(Cn));

		// load는 프로그램 껏다가 다시 킬때 실행됨
		// 프로그램 끌 때 동적할당 받은거 전부 해제했고 다시 켰을 때 행 열 중 행만 동적할당 했으니(생성자)
		//  Cn개 만큼 열들을 다시 할당 후 -> 데이터 읽어들여야 함
		for (int i = 0; i < Cn; i++)
		{
			names[i] = new char[20]; 
			comAddr[i] = new char[50];
			fin.read(names[i], 20); //20 바이트만큼 읽어 i번째 행의 시작주소에 저장
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

	while (stop)
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
			cin.ignore(256, '\n'); //버퍼에 남은데이터 지우기
		} while (cin.fail()); // 문자 입력받으면 fail함수 리턴 값이 1임

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

