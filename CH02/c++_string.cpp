// C++_string.cpp
#include<iostream>
#include<string> //string 클래스에 문자열 사용
#include<algorithm> //string 클래스에 문자열 사용
/*
	cin.getline(comAddr, 50) : 공백 포함 50글자까지 받는다;
	getline(cin,comAddr) : 어디로부터 입력 받는가 ? : 키보드(cin) , 어디에 넣을것인가? : comAddr
*/

using namespace std;
int main()
{
	string name; // 문자열 하나 저장, 크기제한이 없다
	string name2[20]; // 크기제한 없는 문자열을 20개 저장하겠다.
	string comAddr;

	cout << "성명 ? ";
	cin >> name;	//kim
	cin.ignore(100, '\n');

	cout << "회사주소 ? "; //SEOUL 서울시
	getline(cin, comAddr); //전역함수

	cout << name << "," << comAddr << endl;

	transform(name.begin(), name.end(), name.begin(), ::toupper); // 시작부터, 끝까지가 범위고, 시작부터, 전부 대문자로 바꿔라
	//transform(name.begin(), name.end(), name.begin(), ::tolower); // 시작부터, 끝까지가 범위고, 시작부터, 전부 소문자로 바꿔라

	cout << name << "," << comAddr << endl;

	if (name == "KIM")
		cout << "Equal." << endl;
	else
		cout << "Not Equal." << endl;

	return 0;
}