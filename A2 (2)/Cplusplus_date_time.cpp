#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	// ���� �ý��� ��¥�� ��� ���ģ�YYYY-MM
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);

	cout << "���糯¥: " << systemTime.wYear << "��, " << systemTime.wMonth << "��, " << systemTime.wDay << "��" << endl;
	cout << "����ð�: " << systemTime.wHour << "��, " << systemTime.wMinute << "��, " << systemTime.wSecond << "��" << endl;

	systemTime.wYear = 2022;
	systemTime.wMonth = 3;
	systemTime.wDay = 25;
	cout << "��¥: " << systemTime.wYear << "��, " << systemTime.wMonth << "��, " << systemTime.wDay << "��" << endl;

}

/*
���糯¥: 2022��, 3��, 27��
����ð�: 20��, 59��, 28��
��¥: 2022��, 3��, 25��
*/