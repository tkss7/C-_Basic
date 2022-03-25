//binary_��ȭ_ReadWrite.cpp
#include<iostream>
#include<fstream>

//"c:\\windows\\system.ini" ������ "student.txt"�� �߰��Ͻÿ�.
using namespace std;

int main()
{

	const char* sour = "��ȭ.jpg";
	const char* dest = "��ȭCopy2.jpg";
	fstream fin(sour, ios::in | ios::binary);
	fstream fout(dest, ios::out | ios::binary);
	// fstream �� ios::in , ios::out�� ��������������� ifstream, ostream �� ����Ʈ ������ �� �־� �Ƚᵵ �ȴ�.
	if (!fin)
	{
		cout << sour << " ���Ͽ��� ���� !!!" << endl;
		return -1;
	}
	if (!fout)
	{
		cout << dest << " ���Ͽ��� ���� !!!" << endl;
		return -1;
	}

	char buffer[1024];
	while (!fin.eof()) // ���Ϻ���
	{
		fin.read(buffer, 1024);
		int n = fin.gcount();
		fout.write(buffer, n);

	}

	fin.close();
	fout.close();

	cout << "���� ���Ϻ���." << endl;

	return 0;
}