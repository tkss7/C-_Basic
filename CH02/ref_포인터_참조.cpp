//ref_포인터_참조.cpp
#include<iostream>
using namespace std;
/*
	char* str = "kingdom";//C언어에서는 처리가 되었지만 C++에서는 오류다
*/
int main()
{
	int num = 100;
	int* ptr = &num; // ptr에 num의 주소, *ptr은 12
	int** dptr = &ptr; //dptr은 ptr의 시작주소, *dptr = ptr의 값= num의 주소 , **dptr = num의 값인 12

	int& ref = num; // ref와 num은 같은 값을 가리킨다.
	//int& pref = ptr;//참조변수는 값을 참조하는 것이지 포인터를 참조할 수 없다.
	int* (&pref) = ptr; // 이렇게 해야 포인터를 참조 가능
	int** (&dpref) = dptr;

	cout << "num : "<<num<<", ref : " << ref << endl;
	cout << "*ptr : " << *ptr << ", *pref : " << *pref << endl;
	cout << "**dptf : " << **dptr << ", **dpref : " << **dpref << endl;

	const char* str = "kingdom";
	const char* (&strRef) = str;
	cout << "str : " << str << ", strRef : " << strRef << endl;

	return 0;
}