//New_���ڿ� �������� ���.cpp 03/17 ?????
#include<iostream>
using namespace std;

//���ڿ��� �������� �����Ѵ�. �ڵ��߰�
char* ReverseString(const char* src, int len)
{
	char* dest = new char[len+1];
	int i;
	for (i = 0; i < len; i++)
	{
		*(dest + i) = *(src + (len-i-1));
	}
	dest[len] = NULL;
	return dest;
}

int main()
{
	char original[] = "Multi Campus.";
	int x = strlen(original);
	cout << x<<"\n";
	char* copy = ReverseString(original, strlen(original));

	cout << original << "\n";
	cout << copy << "\n";

	delete[] copy;
	copy = NULL;

	return 0;
}