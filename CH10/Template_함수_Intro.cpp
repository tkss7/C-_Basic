//Template_함수_Intro.cpp
#include<iostream>
using namespace std;

//template 키워드 : 템플릿이 정의됨을 알린다.
//	T : 자료형을 결정짓지 않겠다.
// 

template <typename T> // 모형으로 대신만들어 준다. //여기서는 int형 double형 두개를 컴퓨터가 만들어 주는것
//template <class T>  // typename 과 class 키워드가 똑같음 하지만 일반적인 class랑 혼동될수 있으므로 typename 쓰는것을 권장함
T Add(T x, T y)
{
	return x + y;
}

//double Add(double x, double y)
//{
//	return x + y;
//}

int main()
{
	cout << Add(10, 20) << endl; // Add함수가 불려질때 int가 T타입으로 결정됨
	cout << Add<double>(1.1, 2.1) << endl; //type은 생략가능하다


	return 0;
}