//STL_Vector.cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Vector는 동적 배열 구조 이다. (마지막에 추가/삭제 할 때)??? 뭔 개소리야


int main()
{
	vector<int> v; //정수형 동적배열

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(10);
	
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl;

	v[0] = 10;
	int num = v[2];
	v.at(3) = 3;
	// v[0] : 범위를 검사안함
	// v.at(3) : 범위를 검사함
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl << endl;

	cout << " v.size() : " << v.size() << endl; // 실제 유효한 배열요소 크기
	cout << " v.size() : " << v.capacity() << endl; // 벡터용량 : 메모리가 할당되어 있는 공간의 크기

	vector<int> ::iterator it;
	it = v.begin();
	v.erase(it); // begin을 저장한 첫번째 it을 지운다. // 현재위치 삭제
	cout << "v.size() : " << v.size() << endl;
	cout << "v.capacity() : " << v.capacity() << endl;

	v.pop_back();
	v.pop_back();

	cout << "v.size() : " << v.size() << endl;
	cout << "v.capacity() : " << v.capacity() << endl;

	v.shrink_to_fit(); // capacity() = 크기 재조명

	cout << "v.size() : " << v.size() << endl;
	cout << "v.capacity() : " << v.capacity() << endl << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl << endl;

	v.resize(10); //벡터 크기변경, 채운 나머지는 0으로 채운다.

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl << endl;

	cout << "v.size() : " << v.size() << endl;
	cout << "v.capacity() : " << v.capacity() << endl << endl;



	return 0;
}