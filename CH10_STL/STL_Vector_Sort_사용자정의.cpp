//STL_Vector_Sort_���������.cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool compare(int a, int b)
{
	//return a < b; // ��������
	return a > b; // ��������
}

bool compare2(string s1, string s2)
{
	//return s1.size() > s2.size(); //��������
	return s1.size() < s2.size(); // ��������
}
//STL_Vector_Sort_���������.cpp 03/30
int main()
{
	vector<int> v; //������ �����迭
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

	vec2.assign(strArr, strArr + 6); // strArr ~ strArr+6������ vec2�� �Ҵ��Ѵ� = �����Ѵ�?

	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << ", ";
	cout << endl;

	sort(vec2.begin(), vec2.end()); //�ƽ�Ű�ڵ� ����(��)���� ������

	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << ", ";
	cout << endl;

	sort(vec2.begin(), vec2.end(),compare2); //���ڿ� ���̼�

	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << ", ";
	cout << endl;

	return 0;
}