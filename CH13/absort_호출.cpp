//absort_호출.cpp
#include<iostream>
#include<cstdlib>
using namespace std;
int divide(int a, int b);
int main()
{
	int a, b;
input:
	cout << "두 수를 입력 : ?";
	cin >> a >> b;

	try
	{
		cout << "a/b = " << divide(a, b) << endl;
	}
	catch (char exp) // 예외블록이 있더라도 자료형이 맞지 않으면 abort() 함수가 호출된다!!
	{
		cout << "예외발생!!" << endl;
	}

	//abort();

	cout << "End." << endl;
	



	return 0;
}
int divide(int a, int b) //함수를 호출했는데 오류뜨면 부모함수로 리턴된다.
{
	if (b == 0)
		throw b;
	return a / b;
}