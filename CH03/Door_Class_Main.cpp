//Door_Class_main.cpp 03/18
#include<iostream>
#include"Door.h"
//시스템 헤더파일 안에는 #ifndef _DOOR_H_  이런식으로 이미 다 되어있다.
//사용자 정의 파일에 저런식으로 하자!!! 
using namespace std;

int main()
{
    Door d1;
    d1.ShowState();
    d1.Open(); // state = OPEN; 으로 대체가 일어남
    d1.ShowState();

    d1.Close();
    d1.ShowState();

    return 0;
}