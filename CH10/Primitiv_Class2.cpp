//Primitiv_Class2.cpp 03/29
#include<iostream>
using namespace std;

template <typename T>
class Type
{
private:
	T n;
public:
	Type(T _n) // 변환 생성자 : 인자를 하나 갖는 생성자
	{
		cout << "Type("<<typeid(_n).name()<<") "<< endl;
		n = _n;
	}
	T getN()
	{

		return n;
	}

	//operator int() // 형변환 연산자 (명시적, 묵시적 호출 다 허용
	//{
	//	return n;
	//}

	operator T() // 형변환 연산자 (명시적 호출만 허용한다).
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