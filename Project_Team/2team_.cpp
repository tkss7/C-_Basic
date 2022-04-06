//employess.c
#include <iostream>
#include <cstring>
#include<fstream>
#include<vld.h>

using namespace std;
#define EMP_SZ 30

/*
Ű����� ���� ����(names,20), ����(salary), ȸ���ּ�(comAddr,50)�� �Է¹ް� ����Ͻÿ�.
�̶� �ԷµǴ� �Ǽ��� ���� ���ϸ�, ������ "end" �̸� �Է��� �����ϰ�,
�Էµ� ������ ��°�, ���� ����� ���Ͽ� ����Ͻÿ�.

���̺귯���Լ��� ����,���п��θ� �˷��ִ� perror()�Լ��� �ִ�.
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

			cout << "(���� ? (�Է��շ�:end) )";
			cin.getline(_names, 20); //kim['\0], lee, han
			if (strcmp(_names, "end") == 0)
			{
				delete names[i];
				delete comAddr[i];
				break;
			}

			strcpy(names[i], _names);



			cout << "(���� ? )";
			cin >> *(salary + i);
			cin.clear();
			cin.ignore(100, '\n');

			cout << "(ȸ���ּ� ? )";
			cin.getline(_comAddr, 50);
			strcpy(comAddr[i], _comAddr);

		}
		Cn = i;

	}

	void output()//������ ���
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
			cout << "(�������: " << salTot / Cn << ")" << endl;
			cout << "====================\n";

		}


	}//emp_output() end

	void find()//�˻� �˰���
	{
		int i, found;
		char s_name[20];

		while (1)
		{
			cout << "(�˻��� ���� ? (�˻�����:end))";
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
			cout << file << " ���Ͽ��� ���� !!!" << endl;
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
		cout << "���� �Ϸ�!!!!!" << endl;
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
	emp.load();//������� �޸� ����

	while(stop)
	{
		do {

			cout << "1. ������� �Է� " << endl;;
			cout << "2. ������� ��� " << endl;;
			cout << "3. ������� �˻� " << endl;;
			cout << "4. ������� ���� " << endl;;
			cout << "5. ������� ���� " << endl;;
			cout << "Select ? (1~5) ";
			cin >> choice;
			cin.clear();
			cin.ignore(256, '\n');
		} while (cin.fail());

		switch (choice) //�ش�Ǵ� ��ȣ�� ������ �ٽ� �θ�
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