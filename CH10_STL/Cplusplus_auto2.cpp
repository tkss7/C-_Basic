//Cplusplus_auto2.cpp
#include<iostream>
#include<vector>
using namespace std;

int square(int n)
{
	return n * n;
}

int add(int x, int y)	//매개변수는 컴파일시 매개변수 타입을 추론 할 수 없으므로 auto 키워드 불가
//int add(auto x, auto y) == 불가능
{
	return x + y;
}

auto add(int x, double y)	 // 이러한 형태는 가능
{
	return x + y;
}

template <typename T1, typename T2>
auto ADD(T1 x, T2 y)
{
	return x + y;
}

int main()
{
	auto ret = square(3); // 함수가 리턴하는 값을 auto 변수가 받을 수 있다.
	cout << "ret : " << ret << endl;

	auto sum = add(10, 20);
	cout << " sum : " << sum << endl;

	auto sum2 = add(10, 3.5);
	cout << " sum : " << sum2 << endl;

	auto t1 = ADD<int, float>(100, 1.5);

	auto t2 = ADD<int, char>(1, 'A');

	auto t3 = ADD(100, 200);

	cout << "typeid(t1).name() : " << typeid(t1).name() <<
		", " << "typeid(t2).name() : " << typeid(t2).name() <<
		", " << "typeid(t3).name() : " << typeid(t3).name() << endl;

	auto add2 = add; // add : 함수명 => 함수의 주소를 가리킴 , add2 = 함수 포인터 변수
	auto sum3 = add2(100, 7.1);
	cout << "sum3 : " << sum3 << endl;

	return 0;
}