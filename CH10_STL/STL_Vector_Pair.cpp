//STL_Vector_Pair.cpp 03/30
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int >a, pair<int, int>b)
{
	//return a.second < b.second; // 오름차순
	return a.second < b.second; //내림차순
}

int main()
{
	vector<pair<int, int>> v; // 쌍의 데이터를 넣을 수 있음

	v.push_back(make_pair(10, 20));
	v.push_back(make_pair(50, 40));
	v.push_back(make_pair(100, 70));
	v.push_back(make_pair(30, 20));

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ", " << v[i].second << endl;
	cout << endl << endl;

	vector<pair<int, int>> v2;

	v2.push_back(make_pair(1001, 35000000));
	v2.push_back(make_pair(1002, 27000000));
	v2.push_back(make_pair(1003, 37000000));
	v2.push_back(make_pair(1004, 59000000));
	v2.push_back(make_pair(1005, 23000000));

	sort(v2.begin(), v2.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout <<get<0>(v2[i]) << ", " << v2[i].second << endl; // 둘다 가능함
		//cout << v2[i].first << ", " << v2[i].second << endl; // 둘다 가능함
	cout << endl << endl;

	return 0;
}