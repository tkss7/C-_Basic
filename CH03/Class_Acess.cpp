//Class_Acess.cpp 03/17
#include<iostream>
using namespace std;
/*
	protected : ��Ӱ��迡���� �� �� �ִ�.
*/
class Counter
{ // ����Ʈ ���� private��, �������� ���ؼ� ����!

private: // ���������� ��� , Ŭ���� ���� public �޼ҵ� �ȿ����� ��� ����
	int value2 = 100;
public: // �ܺ������� ���
	int value;
	void InCrement()
	{
		value++;  //��������
		value2++; //��������
	}
	int getValue()
	{
		return value2;
	}
};

int main()
{
	Counter cnt;

	cnt.value = 1;  //�ܺ�����
	cnt.InCrement(); //�ܺ����� : Ŭ���� �ۿ��� �����ϴ� ��

	cout << "cnt.value: " << cnt.value << endl; // 2 : �ܺ�����
	cout << "cnt.value2: " << cnt.getValue() << endl; // 2 : �ܺ�����

	return 0;
}