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
	char** names; // names[EMP_SZ][20]�� �ޱ����� ���� ������
	char **comAddr; // comAddr[EMP_SZ][50]�� �ޱ����� ���� ������
	int *salary;
	int Cn, salTot;

public:
	Employee() :Cn(0) {
		names = new char* [EMP_SZ]; // 30���� ���� �迭�����ͷ� �Ҵ�
		comAddr = new char* [EMP_SZ]; // 30���� ���� �迭�����ͷ� �Ҵ�
		salary = new int[EMP_SZ]; // 30�� ���� �Ҵ�
		salTot = 0;
	}
	~Employee() // �Ҵ�� �޸𸮵� ���� ����
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
		char _names[20]; //�Է� �ӽ� ����
		char _comAddr[50]; // �Է� �ӽ� ����

		
		for (i = Cn; i < EMP_SZ; i++)
		{
			names[i] = new char[20]; // 20�� �����Ҵ�( 20byte)
			comAddr[i] = new char[50]; // 50�� �����Ҵ� ( 50byte)

			cout<< "(���� ? (�Է��շ�:end) )";
			cin.getline(_names, 20); // �Է¹��ۿ� 20����Ʈ �Է�
			if (strcmp(_names, "end") == 0)
			{
				delete names[i]; // end �ԷµǸ� ��� �Ҵ� ���� ���� 20byte �Ҵ� ����
				delete comAddr[i]; // end �ԷµǸ� ��� �Ҵ� ���� ���� 50byte �Ҵ� ����
				break;
			}

			strcpy(names[i], _names); // ���� -> �迭�� ����
			


			cout<<"(���� ? )";
			cin >> *(salary+i);
			cin.clear();
			cin.ignore(100, '\n');

			cout<<"(ȸ���ּ� ? )";
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
			cout<<"====================\n";
			cout << "(�������: " << salTot / Cn<<")" << endl;
			cout<<"====================\n";

		}

		// Ŭ���� �����ʹ� (*x).xx �������� �ؾ��ϴµ�?

	}//emp_output() end
	// cin.ignore(1) // ���Ͱ� ����
	void find()//�˻� �˰���
	{
		int i,found;
		char s_name[20];

		while (1)
		{
			cout<<"(�˻��� ���� ? (�˻�����:end))";
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

		fout.write((char*)(&Cn), sizeof(Cn)); // Cn�ּҿ� 4����Ʈ��ŭ ���� ����
		for (int i = 0; i < Cn; i++)
		{
			fout.write(names[i],20); // i ��°���� 20byte�� ���Ͽ� ����
			fout.write((char*)(salary + i), sizeof(salary[0]));
			fout.write(comAddr[i], 50);
		}

		fout.close();
		cout << "���� �Ϸ�!!!!!" << endl;
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

		// load�� ���α׷� ���ٰ� �ٽ� ų�� �����
		// ���α׷� �� �� �����Ҵ� ������ ���� �����߰� �ٽ� ���� �� �� �� �� �ุ �����Ҵ� ������(������)
		//  Cn�� ��ŭ ������ �ٽ� �Ҵ� �� -> ������ �о�鿩�� ��
		for (int i = 0; i < Cn; i++)
		{
			names[i] = new char[20]; 
			comAddr[i] = new char[50];
			fin.read(names[i], 20); //20 ����Ʈ��ŭ �о� i��° ���� �����ּҿ� ����
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

	while (stop)
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
			cin.ignore(256, '\n'); //���ۿ� ���������� �����
		} while (cin.fail()); // ���� �Է¹����� fail�Լ� ���� ���� 1��

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

