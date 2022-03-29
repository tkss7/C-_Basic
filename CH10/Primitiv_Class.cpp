//Primitiv_Class.cpp 03/29
#include<iostream>
using namespace std;

class Type
{
private:
	int n;
public:
	Type(int _n) // 변환 생성자 : 인자를 하나 갖는 생성자
	{
		cout << "Type(int n)" << endl;
		n = _n;
	}
	int getN()
	{
		return n;
	}
	 
	//operator int() // 형변환 연산자 (명시적, 묵시적 호출 다 허용
	//{
	//	return n;
	//}

	explicit operator int() // 형변환 연산자 (명시적 호출만 허용한다).
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
	
	//int num = data1; // num(int)data1; => 가능함 // 묵시적 호출이라 불가능함
	//int num = (int)data1; //정수형으로 반환하고자 할떄 정수형을 찾는다. //명시적 호출

	int num = static_cast<int>(data1); // C++ 형식
	cout << "num :" << num << endl;

}