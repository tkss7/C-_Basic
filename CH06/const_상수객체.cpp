//const_�����ü.cpp
#include<iostream>
using namespace std;

class AAA
{
private:
	mutable int num; //���� ���ȭ�� ����� ���� ���ϴ°� ������ ���⼱ ����� �ִٸ� �˷��� ��

public:
	AAA(int n) : num(n)
	{

	}

	void showData()
	{
		cout << "void showData()" << endl;
		cout << "num : " << num << endl;
	}
	void showData() const // �����ε�
	{
		cout << "void showData() const" << endl;
		cout << "num : " << num << endl;
	}

	void Add(int n) const
	{
		num += n;
	}
};

int main()
{
	AAA a1(200); //�Ϲݰ�ü : �ַξ�
	a1.showData(); // �Ϲݸ޼���� ���ȭ�� �޼��尡 �� ������ �� �켱������ �Ϲݸ޼�����, ���� �Ϲݸ޼��尡 ���ٸ� �׶� ���ȭ�� �޼��带 �����.

	const AAA a2(100); //�����ü : �Ϲ� �޼��� ������ �Ұ���
	a2.showData(); // ����޼��常 ����� �� �ִ�.

	a1.Add(50);
	a1.showData();

	a2.Add(50);
	a2.showData();

	return 0;
}