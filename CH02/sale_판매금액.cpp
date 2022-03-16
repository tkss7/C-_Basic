//sale_판매금액.cpp
#include<iostream>
using namespace std;
/*
	문제] 판매금액을 입력받아 급여를 계산하는 프로그램을 작성한다.(급여계산은 반복되며 -1이면 종료한다)
	1.급여입력은 main()
	2. 급여 계산은 calSalary() 함수에서 계산하여 반환
	기본급 100만원
	인센티브는 판매금액의 12%
	급여는 = 기본급 + 인센티브
	3. 급여출력은 main()

	실행결과
	판매금액을 만원단위로 입력(-1 to end) : 100
	이번달 급여 : 112만원
	판매금액을 만원단위로 입력(-1 to end) : 200
	이번달 급여 : 124만원

*/

int CalSalary(int money); //C++은 선언문생략시 오류뜸

int main()
{
	int sales;

	while (1)
	{
		cout << "판매금액을 만원단위로 입력(-1 to end) : ";
		cin >> sales;
		//

		if (sales==-1)
			break;

		CalSalary(sales);

		cout << "이번달 급여 :" << CalSalary(sales) << "만원" << endl;
	}

	cout << "종료\n";



	return 0;
}
int CalSalary(int money)
{
	return (int)(100 + (money * 0.12));

}