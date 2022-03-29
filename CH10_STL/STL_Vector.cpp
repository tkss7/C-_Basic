//STL_Vector.cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Vector�� ���� �迭 ���� �̴�. (�������� �߰�/���� �� ��)??? �� ���Ҹ���


int main()
{
	vector<int> v; //������ �����迭

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
	// v[0] : ������ �˻����
	// v.at(3) : ������ �˻���
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl << endl;

	cout << " v.size() : " << v.size() << endl; // ���� ��ȿ�� �迭��� ũ��
	cout << " v.size() : " << v.capacity() << endl; // ���Ϳ뷮 : �޸𸮰� �Ҵ�Ǿ� �ִ� ������ ũ��

	vector<int> ::iterator it;
	it = v.begin();
	v.erase(it); // begin�� ������ ù��° it�� �����. // ������ġ ����
	cout << "v.size() : " << v.size() << endl;
	cout << "v.capacity() : " << v.capacity() << endl;

	v.pop_back();
	v.pop_back();

	cout << "v.size() : " << v.size() << endl;
	cout << "v.capacity() : " << v.capacity() << endl;

	v.shrink_to_fit(); // capacity() = ũ�� ������

	cout << "v.size() : " << v.size() << endl;
	cout << "v.capacity() : " << v.capacity() << endl << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl << endl;

	v.resize(10); //���� ũ�⺯��, ä�� �������� 0���� ä���.

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl << endl;

	cout << "v.size() : " << v.size() << endl;
	cout << "v.capacity() : " << v.capacity() << endl << endl;



	return 0;
}