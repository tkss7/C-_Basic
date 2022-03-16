//hello.cpp
/*
*	function == method
	C언어 : 구조적인 프로그래밍 언어, 함수중심, .c
	C++ : 객체지향 프로그래밍 언어, 객체중심(C 언어의 superSet) , .cpp
		: C/C++ 컴파일러
	std : iostream에 선언된 객체들이 std라는 namespace 에 정의되어 있다.
			std에 있는 cout, endl을 사용하겠다
	namespace : 코드가 합쳐지는 과정에서 같은 이름의 함수들이 있으면 충돌한다. 이를 해결하기 위해 영역을 만드는 것이 namespace
	<< : 출력스트림 연산자
	std::endl ==> \n 과 같은 의미임
	std::cout ==> 입출력 라이브러리에 있는 콘솔아웃
*/
#include<iostream>
// 입, 출력등 다양한 메서드를 제공하는 객체지향 라이브러리를 제공하는 헤더파일
int main()
{
	int num = 100;

	std::cout << "hellow world" << std::endl;
	std::cout << "인피니트\n";
	std::cout << "헬스케어" << std::endl;
	std::cout << "num : " << num << std::endl;
	std::cout << 'A' << "," << 3.14 << std::endl;

	return 0;
}