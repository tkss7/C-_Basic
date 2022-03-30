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
    time(&t1);  //시스템 시간을 1900년1월1일 0시 부터 증가한 현재값을 t1에 저장 

    char* str1 = ctime(&t1);
    printf("ctime의 결과 : %s\n", str1);

    struct tm* dateInfo;

    dateInfo = localtime(&t1);    // 현재 날짜시간 정보를 struct tm에 저장

    int year = dateInfo->tm_year + 1900;    //연도에는 1900 더해줌
    int month = dateInfo->tm_mon + 1;    // 월에는 1 더해줌
    int day = dateInfo->tm_mday;
    int hour = dateInfo->tm_hour;
    int min = dateInfo->tm_min;
    int sec = dateInfo->tm_sec;

    printf("timeInfo : %d년 %d월 %d일 %d시 %d분 %d초\n", year, month, day, hour, min, sec);

    return 0;
}