//Textfile_Append.cpp
#include<iostream>
#include<fstream>

//"c:\\windows\\system.ini" 파일을 "student.txt"에 추가하시오.
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
	// fstream 은 ios::in , ios::out을 설정해줘야하지만 ifstream, ostream 은 디폴트 값으로 들어가 있어 안써도 된다.
	if (!fin)
	{
		cout << "student.txt 파일열기 실패 !!!" << endl;
		return -1;
	}
	if (!fout)
	{
		cout << "student.bak 파일열기 실패 !!!" << endl;
		return -1;
	}

	char ch;


	while ((ch = fin.get()) != EOF) //마지막 읽은 EOF(-1)이면 탈출
	{
		fout.put(ch);
	}

	fin.close();
	fout.close();

	cout << "파일복사 !!" << endl;


	return 0;
}