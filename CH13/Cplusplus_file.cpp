//Cplusplus_file.cpp
#include<iostream>

using namespace std;

//extern "C" char* getName(); // extern "C" : C�Լ��� �ؼ��ض�
//extern "C" void Func(const char* msg);
extern "C" //���� ������ ������Ͽ� ��� extern "C" { her.h} �������� ���°� ����ϴ�.
{
	#include"file.h"
}

int main()
{
	char* retName;

	Func("C++ ���� C �Լ� ȣ��.");
	retName = getName();
	printf("name : %s \n", retName);

	return 0;
}