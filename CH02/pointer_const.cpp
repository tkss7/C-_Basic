//pointer_const.cpp
#include<iostream>
using namespace std;

int main()
{
	const int PI = 3.14159; // ������ ���ȭ

	int num1 = 100, num2 = 200;
	const int* p1 = &num1; //�����Ͱ� ����Ű�� ���� ���ȭ //�ַξ�
	//*p1 = 150; // �Ұ� => ���,������
	p1 = &num2; // ����
	cout << "*p1 : " << *p1 << endl;

	int* const p2 = &num2; // �����Ͱ� �������� �ּҸ� ���ȭ
	*p2 = 250; //����
	//p2 = &num1; //�Ұ��� // ������, ���
	cout << "*p2 : " << *p2 << endl;

	const int* const p3 = &num1;
	//p3 = &num2; //�Ұ�
	//*p3 = 150; //�Ұ�

	return 0;
}