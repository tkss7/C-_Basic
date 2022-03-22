//friend_Ŭ����_�����Լ�.cpp
#include<iostream>
using namespace std;

class Counter
{
private:
	int value;
public:
	Counter() :value(0)
	{

	}
	void showData()
	{
		cout << "value : " << value << endl;
	}

	friend void setValue(Counter& ref, int n); //�ܺ����� ���
};
//�����Լ����� ��ü private ��� ���� (Ŭ�������� friend ����)
void setValue(Counter& ref, int n) //�����Լ����� ��ü private ��� ���� (Ŭ�������� friend ����)
{
	ref.value = n; //�ܺ������̶� �ȵ�

}
int main()
{
	Counter cnt;

	cnt.showData();

	setValue(cnt, 5000);
	cnt.showData();


	return 0;
}