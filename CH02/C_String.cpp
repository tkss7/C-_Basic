//C_String.cpp
#include<iostream>
#include<cstring> // C++ 규칙 : c 헤더파일 사용시 확장자 h는 버리고 헤더파일명 앞에 c를 추가한다.
/*
	A객체 (.) ->   
	cin.getline 은 멤버함수 :그 객체에서만 쓸 수 있는 함수
*/

using namespace std;
int main()
{
	char name[20];
	char comAddr[50];

	cout << "성명 ? ";
	cin >> name;	//kim
	cin.ignore(100, '\n');

	cout << "회사주소 ? "; //SEOUL 서울시

	//cin >> comAddr; //cin은 공백전까지만 받음
	//cin.getline(comAddr, 50); // 공백 포함 50글자까지 받는다.
	//cin.getline(comAddr, 50, '\n'); // 공백 포함 50글자까지 받는데 도중에 \n을 만나면 그만 받는다.
	cin.getline(comAddr, 50, '.'); // 공백 포함 50글자까지 받는데 도중에 .을 만나면 그만 받는다.
	 // cin.getline 은 멤버함수 :그 객체에서만 쓸 수 있는 함수
	cout << name << "," << comAddr << endl;

	cout << "strupr(name) : " << strupr(name) << endl; //대문자로 바꿈
	cout << "strlwr(comAddr) : " << strlwr(comAddr) << endl; //소문자로 바꿈

	if (strcmp(name, "KIM") == 0)
		cout << "Equal." << endl;
	else
		cout << "Not Equal." << endl;

	return 0;
}