//Door_Class_main.cpp 03/18
#include<iostream>
#include"Door.h"
//�ý��� ������� �ȿ��� #ifndef _DOOR_H_  �̷������� �̹� �� �Ǿ��ִ�.
//����� ���� ���Ͽ� ���������� ����!!! 
using namespace std;

int main()
{
    Door d1;
    d1.ShowState();
    d1.Open(); // state = OPEN; ���� ��ü�� �Ͼ
    d1.ShowState();

    d1.Close();
    d1.ShowState();

    return 0;
}