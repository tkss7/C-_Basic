//C_C_++�ʱ�ȭ.cpp
#include<iostream>
using namespace std;

class AAA
{
private:
	int value;
public:
	
	explicit AAA(int n) // ����� ȣ�⸸ ����Ѵ�.
	{
		value = n;
	}

	void showData()
	{
		cout << "val : " << value << endl;
	}
	
};
int main()
{
	int n1 = 20; //C style �ʱ�ȭ
	int n2(30); //C++ style �ʱ�ȭ
	cout << "n1: " << n1 << ", n2: " << n2 << endl;

	AAA a1(100); //C++ Style �ʱ�ȭ
	a1.showData();
	//AAA a2 = 200; // C Style �ʱ�ȭ, ���������� C++ Style�� ��ȯ�ȴ�.
	//a2.showData();
	return 0;
}