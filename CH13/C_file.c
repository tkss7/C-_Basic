//C_file.c
#include<stdio.h>

void Func(const char* msg)
{
	printf("msg : %s \n", msg);
	printf("C func() �Լ� ȣ�� ��. \n");
}

char* getName()
{
	static char name[20] = "Hong gil dong";
	return name;
}