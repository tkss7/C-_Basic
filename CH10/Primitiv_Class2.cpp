//Primitiv_Class2.cpp 03/29
#include<iostream>
using namespace std;

template <typename T>
class Type
{
private:
	T n;
public:
	Type(T _n) // ��ȯ ������ : ���ڸ� �ϳ� ���� ������
	{
		cout << "Type("<<typeid(_n).name()<<") "<< endl;
		n = _n;
	}
	T getN()
	{

		return n;
	}

	//operator int() // ����ȯ ������ (�����, ������ ȣ�� �� ���
	//{
	//	return n;
	//}

	operator T() // ����ȯ ������ (����� ȣ�⸸ ����Ѵ�).
	{ 
		cout << "operator T()" << endl;
		return n;
	}
};

int main()
{
	Type<int> data1(100);
	data1 = 200;
	int num = data1;
	cout << "num : " << num << endl;
	cout << "=====================\n";

	Type<char> data2('A');
	char ch = data2;
	cout << "ch : "<<ch << endl;
	cout << "=====================\n";

	Type<double> data3(3.5);
	double dnum = data3;
	cout << "dnum : " << dnum << endl;
	cout << "=====================\n";

	Type<string> data4("multi campus");
	string str = data4;
	cout << "str : " << str << endl;
	cout << "=====================\n";
}