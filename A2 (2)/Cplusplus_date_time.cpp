#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	// 현재 시스템 날짜를 취득 형식：YYYY-MM
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);

	cout << "현재날짜: " << systemTime.wYear << "년, " << systemTime.wMonth << "월, " << systemTime.wDay << "일" << endl;
	cout << "현재시간: " << systemTime.wHour << "시, " << systemTime.wMinute << "분, " << systemTime.wSecond << "초" << endl;

	systemTime.wYear = 2022;
	systemTime.wMonth = 3;
	systemTime.wDay = 25;
	cout << "날짜: " << systemTime.wYear << "년, " << systemTime.wMonth << "월, " << systemTime.wDay << "일" << endl;

}

/*
현재날짜: 2022년, 3월, 27일
현재시간: 20시, 59분, 28초
날짜: 2022년, 3월, 25일
*/