//Data_Class_선언과구현분리.cpp
#include<iostream>
using namespace std;
template <typename T>
class Data
{
private:
	T data;
public:
	Data(T n);


	void setData(T n);

	T getData();

};
template <typename T>	// 아래의 T가 템플릿임을 알린다.
Data<T>::Data(T n) // T타입이템플릿으로 정의된 Data 클래스임을 알린다.
{
	data = n;
}

template <typename T>
void Data<T>::setData(T n)
{
	data = n;
}

template <typename T>
T Data<T>::getData()
{
	return data;
}

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