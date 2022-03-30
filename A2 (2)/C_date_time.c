/*
struct tm
{
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
};
*/

#include<stdio.h>
#include<time.h>

int main()
{
    time_t t1; 
    time(&t1);  //�ý��� �ð��� 1900��1��1�� 0�� ���� ������ ���簪�� t1�� ���� 

    char* str1 = ctime(&t1);
    printf("ctime�� ��� : %s\n", str1);

    struct tm* dateInfo;

    dateInfo = localtime(&t1);    // ���� ��¥�ð� ������ struct tm�� ����

    int year = dateInfo->tm_year + 1900;    //�������� 1900 ������
    int month = dateInfo->tm_mon + 1;    // ������ 1 ������
    int day = dateInfo->tm_mday;
    int hour = dateInfo->tm_hour;
    int min = dateInfo->tm_min;
    int sec = dateInfo->tm_sec;

    printf("timeInfo : %d�� %d�� %d�� %d�� %d�� %d��\n", year, month, day, hour, min, sec);

    return 0;
}