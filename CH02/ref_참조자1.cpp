//ref_������1.cpp
#include<iostream>
using namespace std;

/*
	reference(������ ) : �ϳ��� ������ ����Ű�� ���ϳ��� �̸�
	�ּҿ����ڶ� �ٸ�!!!!

*/
int main()
{
	int salary = 3800000;
	// ������       , ������ ����
	int& r_salary = salary;

	cout << salary << " , " << r_salary << endl;

	r_salary += 200000;
	cout << r_salary << " , " << r_salary << endl;
	cout << &salary << " , " << &r_salary << endl; //�޸𸮸� ���� �Ҵ���� �ʴٴ°��� �� �� �ִ�!!!!

	int* p1 = &salary;
	cout << *p1 << ", " << &p1 << ", " << p1 << endl;
	//int& n2 = 100; // lvalue ����(�̸��� �ο��� ����)
	const int& n3 = 200; //����δ� �����ϴ�(�Ұ����� ���� �ƴϴ�)

	return 0;
}