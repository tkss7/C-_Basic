//94P.cpp
#include<iostream>
#include<cstring>
#include <cctype>
using namespace std;
/*
Wise men say, only fools rush in
But I can't help falling in love with you

Shall I stay? Would it be a sin?
If I can't help, falling in love with you

Like a river flows, surely to the sea
Darling so it goes, some things aren't meant to be ;
*/
int main()
{
	char buf[10001];
	int i, j, count = 0;
	int alpha[26] = { 0 };

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n";
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다.\n";
	cin.getline(buf, 10000, ';');

	for (i = 0; i < strlen(buf) + 1; i++)
	{
		buf[i] = tolower(buf[i]);
		//cout << buf[i];
		if (isalpha(buf[i]) == 2) // 0은 문자아님, 1은 대문자, 2는 소문자
		{
			for (j = 0; j < 26; j++) // a~z까지 26개니까 26번 반복
			{
				if (buf[i] == 97 + j) // 97('a') +0 = a , alpha[0]에 저장, 'a'+1 = 'b', alpha[1]에 저장 ... 'a'+25 = 'z', alpha[25]에 저장
					alpha[j] += 1;
			}
			count++; 
		}
	}
	cout <<endl<< "총 알파벳 수 " << count << endl << endl;

	for (i = 0; i < 26; i++) // alpha배열의 각 열에 저장된 숫자만큼 for문돌려서 * 출력
	{
		cout << (char)('a' + i) << " (" << alpha[i] << ")  : ";
		for (j = 0; j < alpha[i]; j++)
			cout << '*';
		cout << endl;
		}
	
	return 0;
}
