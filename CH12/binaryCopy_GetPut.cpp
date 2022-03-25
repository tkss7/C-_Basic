//binaryCopy_GetPut.cpp
#include<iostream>
#include<fstream>

//"c:\\windows\\system.ini" ������ "student.txt"�� �߰��Ͻÿ�.
using namespace std;

int main()
{

	const char* sour = "��ȭ.jpg";
	const char* dest = "��ȭCopy.jpg";
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

	int ch;
	while ((ch = fin.get()) != EOF)
	{
		fout.put(ch);
	}

	fin.close();
	fout.close();

	cout << "���� ���Ϻ���." << endl;

	return 0;
}