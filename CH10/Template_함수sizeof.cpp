//Template_�Լ�sizeof.cpp
#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
int sizeOf(T tmp)
{
	return sizeof(tmp);
}

//���ø� Ư��ȭ : ���ø��� �ҷ����� ()���� Ÿ�Կ� ���� �����ȴ�.
// ()���� Ÿ���� const char * �̹Ƿ� Ư��ȭ �Լ��� �ҷ�����.
//Ư��ȭ�� ���ø��� �Ϲ� �޼ҵ��߿� �Ϲݸ޼ҵ尡 �켱�̴�.
template<>
int sizeOf<const char *>(const char* tmp)
{
	cout << " sizeOf<const char *>(const char* tmp)" << endl;
	return strlen(tmp);
}

int sizeOf(const char* tmp)
{
	cout << " sizeOf(const char* tmp)" << endl;
	return strlen(tmp);
}

int main()
{
	int n = 100;
	double d = 3.9;

	cout << "sizeOf(n) : " << sizeOf(n) << endl;
	cout << "sizeOf(d) : " << sizeOf(d) << endl;

	const char* str = "Hello World!!!";
	cout << "sizeOf(str) : " << sizeOf<const char *>(str) << endl; 
	//sizeOf(str)�� �Ϲ��Լ� �켱
	//sizeOf<const char *>(str)��  Ư��ȭ�� ���� �ҷ���
	//�������� ���ø� Ư��ȭ�� ���� ������ ������ �ƴѰ� ����.

}