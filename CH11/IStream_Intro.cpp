//IStream_Intro.cpp
#include<cstdio>

namespace myStd
{
	class istream
	{
	public:
		istream& operator>>(char* str)
		{
			gets_s(str, 30);
			return *this;
		}

		istream& operator>>(char& ch)
		{
			scanf("%c%*c", &ch);
			return *this;
		}
		
		istream& operator>>(int& num)
		{
			scanf("%d%*c", &num);
			return *this;
		}

		istream& operator>>(double& d)
		{
			scanf("%lf%*c", &d);
			return *this;
		}
	};
	istream cin;
}

using namespace myStd;

int main()
{
	char msg[30], Ch;
	int Num;
	double dNum;

	printf("input char ? ");
	cin >> Ch;

	printf("input string ? ");
	cin >> msg;

	printf("input int ? ");
	cin >> Num;

	printf("input double ? ");
	cin >> dNum;

	printf("%c, %s, %d, %lf \n", Ch, msg, Num, dNum);

	printf("문자, 정수, 문자열 입력 ? ");
	cin >> Ch >> Num >> msg;

	printf("%c, %s, %d, %lf \n", Ch, msg, Num, dNum);


	return 0;
}