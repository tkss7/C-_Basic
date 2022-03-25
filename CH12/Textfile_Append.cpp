//Textfile_Append.cpp
#include<iostream>
#include<fstream>

//"c:\\windows\\system.ini" ������ "student.txt"�� �߰��Ͻÿ�.
using namespace std;

int main()
{
	//const char* file = "c:\\windows\\system.ini";
	//const char* file1 = "c:\\windows\\system.ini";
	const char* file1 = "student.txt";
	const char* file2 = "student.bak";
	//ifstream fin(file1);
	fstream fin(file1, ios::in);
	//ofstream fout(file2);
	fstream fout(file2, ios::out);
	// fstream �� ios::in , ios::out�� ��������������� ifstream, ostream �� ����Ʈ ������ �� �־� �Ƚᵵ �ȴ�.
	if (!fin)
	{
		cout << "student.txt ���Ͽ��� ���� !!!" << endl;
		return -1;
	}
	if (!fout)
	{
		cout << "student.bak ���Ͽ��� ���� !!!" << endl;
		return -1;
	}

	char ch;


	while ((ch = fin.get()) != EOF) //������ ���� EOF(-1)�̸� Ż��
	{
		fout.put(ch);
	}

	fin.close();
	fout.close();

	cout << "���Ϻ��� !!" << endl;


	return 0;
}