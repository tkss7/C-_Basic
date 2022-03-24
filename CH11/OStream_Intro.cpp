//OStream_Intro.cpp
#include<cstdio>
//using namespace std;
/*
	입,출력 시스템(IStream, OStream)
	OStream을 이해하기 위해 cout 객체를 구현
	<< : 출력스트림 연산자

*/
namespace myStd
{
	const char* endl = "\n";

	class ostream // 클래스 ostream 정의
	{
	public:
		ostream& operator<<(const char* str)
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<<(int n)
		{
			printf("%d", n);
			return *this;
		}
		ostream& operator<<(double d)
		{
			printf("%lf", d);
			return *this;
		}
	};

	ostream cout; //ostream 객체 cout 생성
}
using namespace myStd;
int main()
{
	cout << "Hello world." << endl; // cout<< "Hello word." 이 연산하여 반환하고 그것에 <<endl을 또 연산함

	cout << 3.14159 << " , " << 500 << endl;
	cout << endl;
	cout << 100;
	cout << endl;

	return 0;
}