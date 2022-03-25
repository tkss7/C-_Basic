//TextFile_Student_Load.cpp
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char name[20], dept[30];
	int sid;

	ifstream fin;
	fin.open("student.txt",ios::in); //오픈한 파일의 첫줄 첫칸에 커서를 놓음

	if (!fin) // 파일이 없을때 or 있어도 읽을 권한이 없으면 실패함
	{
		cout << "파일열기 실패 !!!" << endl;
		return -1;
	}

	fin >> sid;
	fin >> name;
	fin >> dept;

	fin.close();

	cout << sid << ", " << name << ", " << dept << endl;



	return 0;
}