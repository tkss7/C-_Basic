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

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�.\n";
	cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�.\n";
	cin.getline(buf, 10000, ';');

	for (i = 0; i < strlen(buf) + 1; i++)
	{
		buf[i] = tolower(buf[i]);
		//cout << buf[i];
		if (isalpha(buf[i]) == 2) // 0�� ���ھƴ�, 1�� �빮��, 2�� �ҹ���
		{
			for (j = 0; j < 26; j++)
			{
				if (buf[i] == 97 + j)
					alpha[j] += 1;
			}
			count++;
		}
	}
	cout <<endl<< "�� ���ĺ� �� " << count << endl << endl;

	for (i = 0; i < 26; i++)
	{
		cout << (char)('a' + i) << " (" << alpha[i] << ")  : ";
		for (j = 0; j < alpha[i]; j++)
			cout << '*';
		cout << endl;
		}
	
	return 0;
}
