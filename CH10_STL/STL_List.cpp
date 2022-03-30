//STL_List.cpp 03/30
// vector<int>::iterator end_it = v.end();     // last element 다음을 가르키는 iterator
#include<iostream>
#include<list> // 2중 링크드 리스트
#include<algorithm>
using namespace std;
/*
	end()함수는 vector에서 가장 마지막 데이터의 바로 다음을 가리키는 iterator를 리턴합니다.
	insert(v.begin(), v.end()) 는 begin 위치부터 end위치의 바로 전까지를 삽입한다. == end()가 
	마지막데이터 바로 다음의 iterator이므로  동적배열의 처음부터 끝까지 원소들을 삽입한다.


	ex) 실시간으로 추가삭제 할때는 list
	ex) 직원이 계속 추가된다 = vector
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
	//	cout << intList[i] << endl; // 노드와 노드가 서로 떨어져있다 == 배열이 아니라서 못씀

	intList.remove(15); //index가 아니라 값을 찾아 삭제함 = 15

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
	it = intList.erase(it); // 현재위치를 삭제함
	it = intList.insert(it, 500);

	for (it = intList.begin(); it != intList.end(); it++)
		cout << *it << ", ";
	cout << endl << endl;;

	list<string> strList;
	list<string>::iterator itr;

	strList.push_back("서울시");
	strList.push_back("부산시");
	strList.push_back("대전시");
	strList.push_back("울산시");

	itr = strList.begin();

	for (itr = strList.begin(); itr != strList.end(); itr++)
		cout << *itr << ", ";
	cout << endl;





}
