//sale_�Ǹűݾ�.cpp
#include<iostream>
using namespace std;
/*
	����] �Ǹűݾ��� �Է¹޾� �޿��� ����ϴ� ���α׷��� �ۼ��Ѵ�.(�޿������ �ݺ��Ǹ� -1�̸� �����Ѵ�)
	1.�޿��Է��� main()
	2. �޿� ����� calSalary() �Լ����� ����Ͽ� ��ȯ
	�⺻�� 100����
	�μ�Ƽ��� �Ǹűݾ��� 12%
	�޿��� = �⺻�� + �μ�Ƽ��
	3. �޿������ main()

	������
	�Ǹűݾ��� ���������� �Է�(-1 to end) : 100
	�̹��� �޿� : 112����
	�Ǹűݾ��� ���������� �Է�(-1 to end) : 200
	�̹��� �޿� : 124����

*/

int CalSalary(int money); //C++�� ���𹮻����� ������

int main()
{
	int sales;

	while (1)
	{
		cout << "�Ǹűݾ��� ���������� �Է�(-1 to end) : ";
		cin >> sales;
		//

		if (sales==-1)
			break;

		CalSalary(sales);

		cout << "�̹��� �޿� :" << CalSalary(sales) << "����" << endl;
	}

	cout << "����\n";



	return 0;
}
int CalSalary(int money)
{
	return (int)(100 + (money * 0.12));

}