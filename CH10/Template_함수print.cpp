//Template_함수print.cpp
#include<iostream>
using namespace std;


//C : 실수형 소숫점 자리수 디폴트 6자리
//C++ : 실수형 소수점 자리수는 내가 입력한 자리수 만큼만 나옴
template <typename T> 
void print(T *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout << endl;
}

void print(char* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << (int)arr[i] << ", ";
	cout << endl;
}

int main()
{
	int x[5] = { 1,2,3,4,5 };
	double d[7] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };

	print(x, sizeof(x) / sizeof(x[0]));
	print(d, sizeof(d) / sizeof(d[0]));

	char c1[5] = { 1,2,3,4,5 };
	print(c1, sizeof(c1) / sizeof(c1[0]));

	char c2[] = { 'A','B','C','D','E','F'};
	print<char>(c2, sizeof(c2) / sizeof(c2[0])); //일반함수가 우선순위, 함수명 옆에 자료형 주면 됨?



}