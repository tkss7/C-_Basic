//friend_Ŭ����.cpp
#include<iostream>
using namespace std;

class AAA
{
private:
	int data;
public:
	void showData()
	{
		cout << "showData() data: "<< data << endl;
	}
	friend class BBB; //BBB Ŭ�������� AAA ��� ������ ���
};

class BBB
{
public:
	void setData(AAA &ref, int n)
	{
		ref.data = n;
	}
};

int main()
{
	AAA a1;
	BBB b1;

	b1.setData(a1, 100);
	a1.showData();

	return 0;
}