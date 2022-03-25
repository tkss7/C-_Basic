#include <iostream>
#include <fstream>
using namespace std;

void showStreamState(ios& stream)
{
	cout << "eof() " << stream.eof() << endl;   //파일 끝 1 파일의 상태정보를 알 수 있음
	cout << "fail() " << stream.fail() << endl; // I/O 실패 1
	cout << "=====================" << endl;
}

int main() 
{
	const char* existFile = "student.txt"; // 존재하는 파일명
	const char* noExistFile = "noexist.txt"; // 존재하지 않는 파일명
	
	ifstream fin(noExistFile); // 존재하지 않는 파일 열기
	if(!fin) 
	{ 
		cout << noExistFile << " 열기 오류" << endl;
		showStreamState(fin); // 스트림 상태 출력

		cout << existFile << " 파일 열기" << endl;
		fin.open(existFile);	
		showStreamState(fin); // 스트림 상태 출력
	}

	// 스트림을 끝까지 읽고 화면에 출력
	int c;
	while((c=fin.get()) != EOF) 
		cout.put((char)c);
	
	cout << endl;
	showStreamState(fin); // 스트림 출력

	fin.close();
}
/*
c:\temp\noexist.txt 열기 오류
eof() 0
fail() 1
=====================
c:\temp\student.txt 파일 열기
eof() 0
fail() 0
=====================
kim
111
computer

eof() 1
fail() 1
=====================
*/