//ref_������_����.cpp
#include<iostream>
using namespace std;
/*
	char* str = "kingdom";//C������ ó���� �Ǿ����� C++������ ������
*/
int main()
{
	int num = 100;
	int* ptr = &num; // ptr�� num�� �ּ�, *ptr�� 12
	int** dptr = &ptr; //dptr�� ptr�� �����ּ�, *dptr = ptr�� ��= num�� �ּ� , **dptr = num�� ���� 12

	int& ref = num; // ref�� num�� ���� ���� ����Ų��.
	//int& pref = ptr;//���������� ���� �����ϴ� ������ �����͸� ������ �� ����.
	int* (&pref) = ptr; // �̷��� �ؾ� �����͸� ���� ����
	int** (&dpref) = dptr;

	cout << "num : "<<num<<", ref : " << ref << endl;
	cout << "*ptr : " << *ptr << ", *pref : " << *pref << endl;
	cout << "**dptf : " << **dptr << ", **dpref : " << **dpref << endl;

	const char* str = "kingdom";
	const char* (&strRef) = str;
	cout << "str : " << str << ", strRef : " << strRef << endl;

	return 0;
}