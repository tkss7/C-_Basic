//Template_함수sizeof.cpp
#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
int sizeOf(T tmp)
{
	return sizeof(tmp);
}

//템플릿 특수화 : 템플릿이 불려질떄 ()안의 타입에 의해 결정된다.
// ()안의 타입이 const char * 이므로 특수화 함수가 불려진다.
//특수화된 템플릿과 일반 메소드중에 일반메소드가 우선이다.
template<>
int sizeOf<const char *>(const char* tmp)
{
	cout << " sizeOf<const char *>(const char* tmp)" << endl;
	return strlen(tmp);
}

int sizeOf(const char* tmp)
{
	cout << " sizeOf(const char* tmp)" << endl;
	return strlen(tmp);
}

int main()
{
	int n = 100;
	double d = 3.9;

	cout << "sizeOf(n) : " << sizeOf(n) << endl;
	cout << "sizeOf(d) : " << sizeOf(d) << endl;

	const char* str = "Hello World!!!";
	cout << "sizeOf(str) : " << sizeOf<const char *>(str) << endl; 
	//sizeOf(str)면 일반함수 우선
	//sizeOf<const char *>(str)면  특수화된 것이 불려짐
	//옛날에는 템플릿 특수화를 자주 썼지만 지금은 아닌거 같다.

}