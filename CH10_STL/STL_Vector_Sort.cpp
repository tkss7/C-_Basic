//STL_Vector_Sort.cpp 03/30
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	vector<char> vec;
	vec.push_back(65);
	vec.push_back('B');
	vec.push_back('a');
	vec.push_back('D');
	vec.push_back('Z');

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ", ";
	cout << endl;

	sort(vec.begin(), vec.end(),less<char>()); // 오름차순 , 디폴트값은 오름차순임

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ", ";
	cout << endl;

	sort(vec.begin(), vec.end(),greater<char>()); // 내림차순 < > 에 자료형을 줘야함

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ", ";
	cout << endl;

	char arr[5] = { 'D','a','f','Z','A' };
	sort(arr, arr + 5,greater<char>());
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ", ";
	cout << endl << endl;


	return 0;
}