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
		cout << file << "파일열기 실패 !!!" << endl;
		return -1;
	}

	int count = 0;
	char buf[100];
	// 2진 파일 출력할 땐 write를 써야한다

	while (!fin.eof()) // fin.eof() : 파일 끝이면 true를 반환 : 100바이트보다 작으면 파일이 있는 양까지만 읽음
	{
		fin.read(buf, 100); // (어디에 읽을지 , 얼마나 읽을지)  ??: 버퍼초기화??
		int n = fin.gcount();
		cout.write(buf, n); //읽어들인 내용을 출력 (버퍼에 있는 내용을 , 개수만큼)
		//buf[n - 1] = '\0';
		//cout << buf << endl;

		count += n;
	}

	cout << "읽은 바이트 수 : " << count << endl;
	fin.close();


	return 0;
}