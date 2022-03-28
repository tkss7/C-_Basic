//Template_Data_Class.cpp
#include<iostream>
using namespace std;

template <typename T>
class Data
{
private:
	T data;
public:
	Data(T n)
	{
		data = n;
	}

	void setData(T n)
	{
		data = n;
	}
	T getData()
	{
		return data;
	}
};

int main()
{
	Data<int> d1(100); //class에 템플릿 사용시 자료형을 반드시 입력해야한다. => 생략 불가
	d1.setData(150);
	cout << "d1.setData(150) : " << d1.getData() << endl;

	Data<double> d2(1.5);
	//d2.setData(150);
	cout << "d2.setData(150) : " << d2.getData() << endl;

	Data<char> d3('A');
	//d3.setData(150);
	cout << "d3.setData(150) : " << d3.getData() << endl;

	return 0;
}