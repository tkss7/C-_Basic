//ramda.cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 짧은 코드 , 금방쓰고 끝나는 코드에서 쓴다.
void sum1(int x, int y)
{
	cout << "sum1() :" << x + y << endl;
}
int main()
{
	//1. 일반함수 호출
	sum1(10, 20);

	//2. 람다함수 호출
	[](int x, int y)
	{
		cout << "sum1()과 동일한 lamda 함수 :" << x + y << endl;
	}(10, 30);

	//3. 합을 구하는 변수에 저장하는 람다
	int sum = 0;
	[&sum](int x, int y) {sum = x + y; }(10, 30); //[캡쳐] : 외부에 정의된 변수를 사용할 때 사용
	cout << "sum : " << sum << endl;

	//4. for_each를 사용하는 람다
	vector<int>v = { 1,2,3,4,5 };
	for_each(v.begin(), v.end(), [](int n) {cout << n << ","; }); // begin(1) 부터 end 바로전까지(5) 한번씩 값을 가져와 람다함수에 넣음
	cout << endl;

	int sum2 = 0;
	for_each(v.begin(), v.end(), [&sum2](int n) {sum2 += n; }); // 한번만 구하면 된다면 이런식으로 람다를 쓰는거 같다.
	cout << "sum2 : " << sum2 << endl;


	//5. 람다명  사용하는 람다함수
	double pi = 3.14159;
	auto calc = [pi](int r)->double {return pi * r * r; };
	cout << "면적 : " << calc(5) << endl;

	int num = 10, num2;
	auto f1 = [num]() {cout << num * num << endl; };
	f1();

	auto f2 = [num]()->int {return num * num; }; // 인라인 함수화 가 가능하다. = 호출부에 바로 실행코드의 대체가 일어난다.
	cout << f2() << endl;

	auto f3 = [num, &num2]() {num2 = num * num; }; //&없음 : 저장된 값을 쓰겠다. , &있음 : 값을 끌어다 변경된 값을 저장하겠다.
	f3();
	cout << "num2 : " << num2 << endl;

	return 0;
}