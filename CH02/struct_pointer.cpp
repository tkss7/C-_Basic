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
	//구조체를 하나의 자료형으로 사용 struct로 선언하면 다음엔 구조체변수명으로 선언가능
	Retvalue R;

	R = PlusMinus(100, 30);

	cout << "100+30 = " << R.retValue1 << endl;
	cout << "100-30 = " << R.retValue2 << endl;

	return 0;
}