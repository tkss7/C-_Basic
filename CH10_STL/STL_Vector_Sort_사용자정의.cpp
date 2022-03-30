//STL_Vector_Sort_사용자정의.cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool compare(int a, int b)
{
	//return a < b; // 오름차순
	return a > b; // 내림차순
}

bool compare2(string s1, string s2)
{
	//return s1.size() > s2.size(); //내림차순
	return s1.size() < s2.size(); // 오름차순
}
//STL_Vector_Sort_사용자정의.cpp 03/30
int main()
{
	vector<int> v; //정수형 동적배열
	vector<int>::iterator it;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(10);
	v.push_back(4);
	v.push_back(50);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ", ";
	cout << endl;

	sort(v.begin(), v.end(),compare);

	it = v.begin();
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << ", ";
	cout << endl;
	cout << endl;

	vector<string> vec2;
	string strArr[] = { "watermelon","peach","apple","banana","blueberry","grape" };

	vec2.assign(strArr, strArr + 6); // strArr ~ strArr+6까지를 vec2에 할당한다 = 대입한다?

	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << ", ";
	cout << endl;

	sort(vec2.begin(), vec2.end()); //아스키코드 기준(순)으로 정렬함

	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << ", ";
	cout << endl;

	sort(vec2.begin(), vec2.end(),compare2); //문자열 길이순

	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << ", ";
	cout << endl;

	return 0;
}