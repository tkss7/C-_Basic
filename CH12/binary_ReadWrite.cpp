//binary_ReadWrite.cpp ??
#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	const char* file = "c:\\windows\\system.ini";
	//const char* file = "student.txt";
	ifstream fin(file, ios::binary);

	if (!fin)
	{
		cout << file << "���Ͽ��� ���� !!!" << endl;
		return -1;
	}

	int count = 0;
	char buf[100];
	// 2�� ���� ����� �� write�� ����Ѵ�

	while (!fin.eof()) // fin.eof() : ���� ���̸� true�� ��ȯ : 100����Ʈ���� ������ ������ �ִ� ������� ����
	{
		fin.read(buf, 100); // (��� ������ , �󸶳� ������)  ??: �����ʱ�ȭ??
		int n = fin.gcount();
		cout.write(buf, n); //�о���� ������ ��� (���ۿ� �ִ� ������ , ������ŭ)
		//buf[n - 1] = '\0';
		//cout << buf << endl;

		count += n;
	}

	cout << "���� ����Ʈ �� : " << count << endl;
	fin.close();


	return 0;
}