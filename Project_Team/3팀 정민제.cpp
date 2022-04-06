//employess.c
#include <iostream>
#include <fstream>
using namespace std;
#define EMP_SZ 30
#pragma warning(disable:4996)


char StackNames[EMP_SZ][20], StackAddrs[EMP_SZ][50];
int Cn = 0;


class Employee
{
private:
	char* HeapNames[EMP_SZ];
	int salary[EMP_SZ];
	char* HeapAddrs[EMP_SZ];
public:

	void Input()
	{
		int i = 0;

		for (i = 0; i < EMP_SZ; i++)
		{

			cout << "\n이름이 뭐예요? (입력종료:end)" << endl;
			cin >> StackNames[i];
			cout << endl;

			if (strcmp(StackNames[i], "end") == 0)
				break;


			cout << "연봉 얼마나 되십니까?" << endl;
			cin >> salary[i];
			cout << endl;
			cout << "회사 위치는 어디예요?" << endl;
			cin >> StackAddrs[i];
			cout << endl;

			Cn = i;
		}

		for (i = 0; i <= Cn; i++)
		{
			HeapNames[i] = new char[strlen(StackNames[i]) + 1];
			strcpy(HeapNames[i], StackNames[i]);

			HeapAddrs[i] = new char[strlen(StackAddrs[i] + 1)];
			strcpy(HeapAddrs[i], StackAddrs[i]);
		}

	}

	void Output()
	{
		int i, salTot = 0;

		for (i = 0; i <= Cn; i++)
		{
			cout << HeapNames[i] << ", " << salary[i] << ", " << HeapAddrs[i] << endl;

			salTot += salary[i];
		}

		cout << "====================" << endl;
		cout << "월급평균: " << salTot / (Cn + 1) << endl;
		cout << "====================" << endl;


	}

	void Save()
	{
		ofstream fout("Employee.txt", ios::out);

		if (!fout)
		{
			cout << "파일저장 실패!!!" << endl;
			return;
		}

		fout << "[입력하신 총 " << (Cn + 1) << "명의 사원 정보를 보여드립니다.]\n" << endl;
		for (int i = 0; i <= Cn; i++)
		{
			fout << HeapNames[i] << " ";
			fout << salary[i] << " ";
			fout << HeapAddrs[i] << "\n" << endl;
		}

		fout.close();

		cout << "입력하신 내용이 Employee.txt 에 저장되었습니다." << endl;
	}
};
	


int main()
{
	int choice, stop = 1;
	Employee GO;

	while (stop)
	{
		cout << "1. 사원정보 입력" << endl;
		cout << "2. 사원정보 출력" << endl; 
		cout << "3. 사원정보 저장 " << endl;
		cout << "4. 프로그램 종료 " << endl;
		cout << "Select ? (1 ~ 4) " << endl;

		cin >> choice;

		switch (choice)
		{
		case 1: GO.Input();
			break;
		case 2: GO.Output();
			break;
		case 3: GO.Save();
			break;
		case 4:
			exit(1);
			break;
		};

		cout << "모두 확인완료되었습니다.\n" << endl;
	;
	}
	
	return 0;
}



