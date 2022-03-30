//STL_List.cpp 03/30
// vector<int>::iterator end_it = v.end();     // last element ������ ����Ű�� iterator
#include<iostream>
#include<list> // 2�� ��ũ�� ����Ʈ
#include<algorithm>
using namespace std;
/*
	end()�Լ��� vector���� ���� ������ �������� �ٷ� ������ ����Ű�� iterator�� �����մϴ�.
	insert(v.begin(), v.end()) �� begin ��ġ���� end��ġ�� �ٷ� �������� �����Ѵ�. == end()�� 
	������������ �ٷ� ������ iterator�̹Ƿ�  �����迭�� ó������ ������ ���ҵ��� �����Ѵ�.


	ex) �ǽð����� �߰����� �Ҷ��� list
	ex) ������ ��� �߰��ȴ� = vector
*/
int main()
{
	list<int> intList;
	list<int>::iterator it;

	for (int i = 0; i < 10; i++)
		intList.push_back(i + 10);

	for (it = intList.begin(); it != intList.end(); it++)
		cout << *it << ", ";
	cout << endl;


	cout << "intList.size() : " << intList.size() << endl;
	//for (int i = 0; i < intList.size(); i++)
	//	cout << intList[i] << endl; // ���� ��尡 ���� �������ִ� == �迭�� �ƴ϶� ����

	intList.remove(15); //index�� �ƴ϶� ���� ã�� ������ = 15

	for (it = intList.begin(); it != intList.end(); it++)
		cout << *it << ", ";
	cout << endl;

	intList.push_back(100);
	intList.push_back(200);
	intList.push_front(300);

	for (it = intList.begin(); it != intList.end(); it++)
		cout << *it << ", ";
	cout << endl;

	it = intList.begin();
	it++;
	it++;
	it = intList.erase(it); // ������ġ�� ������
	it = intList.insert(it, 500);

	for (it = intList.begin(); it != intList.end(); it++)
		cout << *it << ", ";
	cout << endl << endl;;

	list<string> strList;
	list<string>::iterator itr;

	strList.push_back("�����");
	strList.push_back("�λ��");
	strList.push_back("������");
	strList.push_back("����");

	itr = strList.begin();

	for (itr = strList.begin(); itr != strList.end(); itr++)
		cout << *itr << ", ";
	cout << endl;





}
