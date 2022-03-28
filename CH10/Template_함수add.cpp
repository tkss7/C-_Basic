//Template_ÇÔ¼öadd.cpp
#include<iostream>
#include<cstring>
#include<vld.h>
using namespace std;

template <typename T>
T Add(T x, T y)
{
	return x + y;
}


template <typename T1, typename T2>
T1 Add(T1 x, T2 y)
{
	return x + y;
}

template <typename T>
T Add(T x[], int size)
{
	cout << "T Add(T x, int size)" << endl;
	T sum = 0;
	for (int i = 0; i < size; i++)
		sum += x[i];
	return sum;
}

 char* Add( char* c1,  char* c2)
{
	 //char* tmp = new char[strlen(c1)+strlen(c2)+1];
	 //strcpy(tmp, c1);

	 //return strcat(tmp, c2);
	 cout << "char* Add( char* c1,  char* c2)" << endl;
	 int len = (strlen(c1) + strlen(c2)) + 1;
	 char* ptr = new char[len];
	 strcpy(ptr, c1);
	 strcat(ptr, c2);
	 return ptr;

}

const char* Add(const char* c1, const char* c2)
 {
	 //char* tmp = new char[strlen(c1)+strlen(c2)+1];
	 //strcpy(tmp, c1);

	 //return strcat(tmp, c2);
	 cout << "char* Add(const char* c1, const char* c2)" << endl;
	 int len = (strlen(c1) + strlen(c2)) + 1;
	 char* ptr = new char[len];
	 strcpy(ptr, c1);
	 strcat(ptr, c2);
	 return ptr;

 }

int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(1.5, 20) << endl;

	int arr[5] = { 10,20,30,40,50 };
	cout << Add(arr, 5) << endl;

	double arr2[5] = { 10.1,20.1,30.1,40.1,50.1 };
	cout << Add(arr2, 5) << endl;



	char s1[] = "king", s2[] = "dom";

	//char* tmp = Add(s1, s2);
	//cout << tmp << endl;
	//delete[] tmp;
	char* ref;
	ref = Add(s1, s2);
	cout << ref << endl;
	delete[] ref;

	const char* ref2;
	ref2 = Add("Multi ", "Campus");
	cout << ref2 << endl;
	delete[] ref2;




}