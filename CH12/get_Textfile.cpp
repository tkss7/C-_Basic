//get_Textfile.cpp
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	const char* file = "student.txt";
	ifstream fin(file, ios::in);

	if (!fin)
	{
		cout << "파일열기 실패 !!!" << endl;
		return -1;
	}

	char ch;
	int cn = 0;

	while ((ch = fin.get()) != EOF) //마지막 읽은 EOF(-1)이면 탈출
	{
		cout << ch;
		cn++;
	}
	cout << "\n읽은 바이트 수 : " << cn << endl;
	fin.close();


	return 0;
}