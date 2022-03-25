//binary_국화_ReadWrite.cpp
#include<iostream>
#include<fstream>

//"c:\\windows\\system.ini" 파일을 "student.txt"에 추가하시오.
using namespace std;

int main()
{

	const char* sour = "국화.jpg";
	const char* dest = "국화Copy2.jpg";
	fstream fin(sour, ios::in | ios::binary);
	fstream fout(dest, ios::out | ios::binary);
	// fstream 은 ios::in , ios::out을 설정해줘야하지만 ifstream, ostream 은 디폴트 값으로 들어가 있어 안써도 된다.
	if (!fin)
	{
		cout << sour << " 파일열기 실패 !!!" << endl;
		return -1;
	}
	if (!fout)
	{
		cout << dest << " 파일열기 실패 !!!" << endl;
		return -1;
	}

	char buffer[1024];
	while (!fin.eof()) // 파일복사
	{
		fin.read(buffer, 1024);
		int n = fin.gcount();
		fout.write(buffer, n);

	}

	fin.close();
	fout.close();

	cout << "이진 파일복사." << endl;

	return 0;
}