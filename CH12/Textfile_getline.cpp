//Textfile_getline.cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	const char* file = "c:\\windows\\system.ini";
	//const char* file = "student.txt";
	ifstream fin(file, ios::in);

	if (!fin)
	{
		cout << file <<"파일열기 실패 !!!" << endl;
		return -1;
	}

	char buffer[100];

	//getline은 읽기를 성공하면 true를 반환한다.
	while (fin.getline(buffer, 100)) // string의 getline 보단 이것을 더쓴다 => 속도도 더 빠르고 메모리도 필요한 만큼만 사용하므로,
	{
		cout << buffer << endl;
	}
	fin.close();
	cout << "=====================\n";

	const char* file2 = "student.txt";
	ifstream fin2(file2, ios::in); // C++의 stream은 재정의가 안되므로 fin.close()를 해도 똑같은 변수명을 또 쓸 수 없다.

	if (!fin2)
	{
		cout << file2 <<"파일열기 실패 !!!" << endl;
		return -1;
	}

	string line;

	while (getline(fin2, line)) // cin을 주면 키보드에서 읽는것
	{
		cout << line << endl;
	}
	fin2.close();

	return 0;
}