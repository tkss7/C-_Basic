//Cplusplus_file.cpp
#include<iostream>

using namespace std;

//extern "C" char* getName(); // extern "C" : C함수로 해석해라
//extern "C" void Func(const char* msg);
extern "C" //양이 많으면 헤더파일에 담고 extern "C" { her.h} 형식으로 쓰는게 깔끔하다.
{
	#include"file.h"
}

int main()
{
	char* retName;

	Func("C++ 에서 C 함수 호출.");
	retName = getName();
	printf("name : %s \n", retName);

	return 0;
}