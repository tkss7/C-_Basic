//struct_pointer.cpp
#include<iostream>
using namespace std;

struct Retvalue
{
	int retValue1;
	int retValue2;
};

Retvalue PlusMinus(int n1, int n2)
{
	struct Retvalue R;
	//cout << R.retValue1 << ", " << R.retValue2 << endl;
	R.retValue1 = n1 + n2;
	R.retValue2 = n1 - n2;
	return R;
}

int main()
{
	//����ü�� �ϳ��� �ڷ������� ��� struct�� �����ϸ� ������ ����ü���������� ���𰡴�
	Retvalue R;

	R = PlusMinus(100, 30);

	cout << "100+30 = " << R.retValue1 << endl;
	cout << "100-30 = " << R.retValue2 << endl;

	return 0;
}