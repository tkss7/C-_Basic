//TextFile_Student_Save.cpp
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char name[20], dept[30];
	int sid;

	cout << "성명 ? ";
	cin >> name;

	cout << "학번(숫자) ? ";
	cin >> sid;

	cout << "학과 ? ";
	cin >> dept;

	//ofstream fout; 
	//fout.open("student.txt");

	ofstream fout("student.txt"); //위의 것과 이거 둘다 가능함

	if (!fout)	// 열기에 성공하면 true : 메모리공간이 없거나 파일이 있는데 write할 권한이 없거나 하면 실행됨
	{
		cout << "파일열기 실패 !!" << endl;
		return -1;
	}

	fout << sid << endl;
	fout << name << endl;
	fout << dept << endl;

	fout.close();

	cout << "student.txt Save." << endl;




	return 0;
}