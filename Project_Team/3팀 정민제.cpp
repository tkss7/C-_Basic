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

			cout << "\n�̸��� ������? (�Է�����:end)" << endl;
			cin >> StackNames[i];
			cout << endl;

			if (strcmp(StackNames[i], "end") == 0)
				break;


			cout << "���� �󸶳� �ǽʴϱ�?" << endl;
			cin >> salary[i];
			cout << endl;
			cout << "ȸ�� ��ġ�� ��𿹿�?" << endl;
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
		cout << "�������: " << salTot / (Cn + 1) << endl;
		cout << "====================" << endl;


	}

	void Save()
	{
		ofstream fout("Employee.txt", ios::out);

		if (!fout)
		{
			cout << "�������� ����!!!" << endl;
			return;
		}

		fout << "[�Է��Ͻ� �� " << (Cn + 1) << "���� ��� ������ �����帳�ϴ�.]\n" << endl;
		for (int i = 0; i <= Cn; i++)
		{
			fout << HeapNames[i] << " ";
			fout << salary[i] << " ";
			fout << HeapAddrs[i] << "\n" << endl;
		}

		fout.close();

		cout << "�Է��Ͻ� ������ Employee.txt �� ����Ǿ����ϴ�." << endl;
	}
};
	


int main()
{
	int choice, stop = 1;
	Employee GO;

	while (stop)
	{
		cout << "1. ������� �Է�" << endl;
		cout << "2. ������� ���" << endl; 
		cout << "3. ������� ���� " << endl;
		cout << "4. ���α׷� ���� " << endl;
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

		cout << "��� Ȯ�οϷ�Ǿ����ϴ�.\n" << endl;
	;
	}
	
	return 0;
}



