//Primitiv_Class.cpp 03/29
#include<iostream>
using namespace std;

class Type
{
private:
	int n;
public:
	Type(int _n) // ��ȯ ������ : ���ڸ� �ϳ� ���� ������
	{
		cout << "Type(int n)" << endl;
		n = _n;
	}
	int getN()
	{
		return n;
	}
	 
	//operator int() // ����ȯ ������ (�����, ������ ȣ�� �� ���
	//{
	//	return n;
	//}

	explicit operator int() // ����ȯ ������ (����� ȣ�⸸ ����Ѵ�).
	{
		return n;
	}
};

int main()
{
	Type data1(100);

	data1 = 200;
	//data1 = Type(200);
	cout << "data1.get() : " << data1.getN() << endl;
	cout << "============================\n";
	
	//int num = data1; // num(int)data1; => ������ // ������ ȣ���̶� �Ұ�����
	//int num = (int)data1; //���������� ��ȯ�ϰ��� �ҋ� �������� ã�´�. //����� ȣ��

	int num = static_cast<int>(data1); // C++ ����
	cout << "num :" << num << endl;

}