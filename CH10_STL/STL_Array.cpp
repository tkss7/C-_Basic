//STL_Array.cpp 03/30
#include<iostream>
#include<array>
#include<algorithm>
#include<string>
using namespace std;

void funcA(array<int, 10> tmp )
{
	cout << sizeof(tmp) << ", " << tmp.size() << endl; //�����̳��� �迭�� �迭 ��ü�� ������ �ѱ��.
	//			40						10
}

int main()
{
	array<int, 10> arr1 = { 1,2,3,4,5,6,7 };

	cout << "arr1.size() : " << arr1.size() << endl;
	for (int i = 0; i < arr1.size(); i++)
		cout << arr1[i] << ", ";
	cout << endl;

	cout << "arr1.at(0) : " << arr1.at(0) << endl;
	cout << "arr1.at(1) : " << arr1.at(1) << endl;
	cout << "arr1.at(2) : " << arr1.at(2) << endl;

	cout << "arr1[0] : " << arr1[0] << endl;
	cout << "arr1[1] : " << arr1[1] << endl;
	cout << "arr1[2] : " << arr1[2] << endl;
	//cout << "arr1[11] : " << arr1[11] << endl;

	cout << "�迭�ּ�" << endl;
	cout << "arr.data() : " << arr1.data() << endl; // �迭�� �����ּ�
	cout << "*(arr.data()) : " << *(arr1.data()) << endl; // �迭�� �����ּ�
	cout << "*(arr.data()+1) : " << *(arr1.data()+1) << endl; // �迭�� �����ּ�
	cout << "*(arr.data()+2) : " << *(arr1.data()+2) << endl; // �迭�� �����ּ�

	cout << " arr1.front() : " << arr1.front() << endl;
	cout << " arr1.back() : " << arr1.back() << endl;
	
	array<int, 10>::iterator it;
	arr1.fill(0); // �޸��ּҸ� 0���� ä���

	for (it = arr1.begin(); it != arr1.end(); it++)
		cout << *it << ' ';
	cout << endl;

	array<string, 3> arr2 = { "���","�ٳ���","����" };
	array<string, 3> arr3 = { "apple","banana","grape" };

	arr2.swap(arr3);
	for (int i = 0; i < arr2.size(); i++)
		cout << arr2[i] << ", ";
	cout << endl;

	cout << sizeof(arr1) << "," << sizeof(arr1[0]) << endl;

	funcA(arr1);

	return 0;
}