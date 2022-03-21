#include <iostream>
#include<string>
#include<cstring>
#include<vld.h>
using namespace std;

/*
다음과 같이 실행하는 함수 중복정의를 작성하시오.

실행결과
30 20
100 50
Z A
5.555 1.111
campus multi
캠퍼스 멀티
*/
void swap(int *n1, int *n2)
{
	int tmp;
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
void swap(int& n1, int& n2)
{
	int tmp;
	tmp = n1;
	n1 = n2;
	n2 = tmp;
}
void swap(char* c1, char* c2)
{
	char tmp;
	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}
void swap(double* d1, double* d2)
{
	double tmp;
	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}
void swap(string& s1, string& s2)
{
	string tmp;
	tmp = s1;
	s1 = s2;
	s2 = tmp;
}
void swap(char *c1, char *c2, int num)
{
	char* tmp = new char[num];
	strcpy(tmp, c1);
	strcpy(c1, c2);
	strcpy(c2, tmp);

	delete[] tmp;
}
int main()
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;

	num1 = 50, num2 = 100;
	swap(num1, num2);
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	cout << ch1 << ' ' << ch2 << endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	cout << dbl1 << ' ' << dbl2 << endl;

	string s1 = "multi", s2 = "campus";
	swap(s1, s2);
	cout << s1 << ' ' << s2 << endl;

	char s3[20] = "멀티", s4[20] = "캠퍼스";
	swap(s3, s4, sizeof(s3));
	cout << s3 << ' ' << s4 << endl;

	return 0;
}
